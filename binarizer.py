#!/usr/bin/env python


# AGM BINARIZER
# Authors: KoffeinFlummi, sutt0n

# DESCRIPTION
# Build script for binarizing the entirety of a multi-PBO
# project without the mind-numbing chore of confirming 20
# different things.

# PREPARATION
# This thing is WIP and for now you need to copy some
# folders from Arma 3 Tools to Arma 3 for it to work
# (CfgConvert, FileBank, DSSignFile).

# SELECTING PBOs
# By default all PBOs that have modifications since the last
# binarization are binarized. You can also start the script
# with the PBOs you want to binarize as arguments.
# e.g.: python binarizer.py AGM_Core AGM_Resting

# PACKING / BINARIZING
# To only pack a certain addon, place an empty file called
# ".PACKONLY" inside of the respective addon folder.

# CREATING THE EXE
# The .exe is created using cx_Freeze, which can be found here:
# http://cx-freeze.sourceforge.net/
#
# python cxfreeze --target-dir dist P:\path\to\agm\binarizer.py
#
# The files are then packed into a single self-extracting exe
# using WinRAR.


import os
import sys
import shutil
import subprocess
import winreg
import threading
import time

if getattr(sys, "frozen", False):
    scriptpath = os.path.dirname(sys.executable) # go one up from temp extracting folder
else:
    scriptpath = os.path.realpath(__file__)

if getattr(sys, "frozen", False): # script is run as .exe, ask the user for these values.
  print("###################################")
  print("#          AGM Binarizer          #")
  print("# Authors: KoffeinFlummi, sutt0n  #")
  print("###################################")

  print("\n# PATH TO PRIVATE KEY")
  print("(If you don't enter anything, the PBOs will not be signed.)")
  privatekey = input("> ")

  print("\n# ARMA INSTALLATION PATH")
  print("(If you don't enter anything, the path will be read from the registry.)")
  arma = input("> ")

  print("\n# ARMA TOOLS INSTALLATION PATH")
  print("(If you don't enter anything, the path will be read from the registry.)")
  armatools = input("> ")

  print("\n# MOD DIRECTORY")
  print("(If you don't enter anything, the Arma installation directory will be used.)")
  moddir = input("> ")

  print("\n# MOD FOLDER (including @)")
  print("(If you don't enter anything, '@AGM_dev' will be used.)")
  modfolder = input("> ")
  if modfolder == "":
    modfolder = "@AGM_dev"

  print("")

else:
  # Path to .biprivatekey file. If not set, addon will not be signed.
  privatekey   = ""#C:\\Programme\\Steam\\SteamApps\\common\\Arma 3 Tools\\AGM.biprivatekey" # if set to anything other that "" it will sign the addons

  # Path to Arma installation. If not set, registry values will be used.
  arma         = ""

  # Path to Arma tools. If not set, registry values will be used.
  armatools    = ""

  # Path to mod storage. If not set, Arma 3 directory will be used. Not including modfolder.
  moddir       = ""

  # Name of the mod folder. REQUIRED!
  modfolder    = "@AGM_dev"

# set this to false once bohemia fixes their stuff and you don't need to manually move files from temp anymore
movemanually = False

def get_arma_path():
  """ Get the installation directory of Arma 3 """
  global arma
  if bool(arma):
    return arma

  # This might throw an exception, but those will be caught outside of this function.
  reg = winreg.ConnectRegistry(None, winreg.HKEY_LOCAL_MACHINE)
  key = winreg.OpenKey(reg, r"SOFTWARE\Wow6432Node\bohemia interactive\arma 3")
  return winreg.EnumValue(key,1)[1]

def get_armatools_path():
  """ Get the installation directory of the Arma 3 Tools """
  global armatools
  if bool(armatools):
    return armatools

  # This might throw an exception, but those will be caught outside of this function.
  reg = winreg.ConnectRegistry(None, winreg.HKEY_LOCAL_MACHINE)
  key = winreg.OpenKey(reg, r"SOFTWARE\Wow6432Node\bohemia interactive\addonbuilder")

  return os.path.dirname(winreg.EnumValue(key,0)[1])

def folder_mod_time(path):
  """ Recursively gets the latest modification date for any file in a folder and it's subfolders. """
  if not os.path.isdir(path):
    return os.path.getmtime(path)

  maximum = os.path.getmtime(path)
  for thingy in os.listdir(path):
    maximum = max([folder_mod_time(os.path.join(path, thingy)), maximum])

  return maximum

def check_for_changes(module_name):
  """ Checks if a folder had modifications after the last binarization. """
  try:
    pbo_path     = os.path.join(moddir if bool(moddir) else get_arma_path(), modfolder, "Addons", module_name.lower()+".pbo")
    project_path = os.path.join(os.path.dirname(scriptpath), module_name)
    return folder_mod_time(project_path) > os.path.getmtime(pbo_path)
  except: # File not found or some other weirdness
    return True

def get_modules():
  """ Get all the folders that need binarization """

  # User manually defined modules to be binarized, use those.
  if len(sys.argv) > 1:
    return sys.argv[1:]

  # Nothing was specifed, binarize all new PBOs.
  root = os.path.dirname(scriptpath)
  modules = []
  for module in os.listdir(root):
    if module[0] != "." and os.path.isdir(os.path.join(root, module)) and check_for_changes(module) and not os.path.exists(os.path.join(root, module, ".DONTPACK")):
      modules.append(module)

  return modules

def binarize(module_name):
  """ Binarizes the given module """
  global moddir, modfolder, privatekey, movemanually

  tempfolder        = os.path.join(os.environ["USERPROFILE"], "AppData", "Local", "Temp") # hardcoded, but who cares?

  addonbuilder_path = os.path.join(get_armatools_path(), "AddonBuilder", "AddonBuilder.exe")
  source_path       = os.path.join(os.path.dirname(scriptpath), module_name)
  destination_path  = os.path.join(moddir if bool(moddir) else get_arma_path(), modfolder, "Addons")
  include_path      = os.path.join(os.path.dirname(scriptpath), "include.txt")
  final_path        = os.path.join(destination_path, module_name+".pbo")

  packonly_path     = os.path.join(source_path, ".PACKONLY")
  if os.path.exists(packonly_path):
    temp_path       = os.path.join(os.path.dirname(scriptpath), module_name+".pbo")
  else:
    temp_path       = os.path.join(tempfolder, module_name+".pbo")

  binarize_path     = os.path.join(get_armatools_path(), "Binarize", "binarize.exe")
  convert_path      = os.path.join(get_armatools_path(), "CfgConvert", "CfgConvert.exe")
  filebank_path     = os.path.join(get_armatools_path(), "FileBank", "FileBank.exe")
  signfile_path     = os.path.join(get_armatools_path(), "DSSignFile", "DSSignFile.exe")

  args = [
    addonbuilder_path,
    source_path,
    destination_path,
    "-prefix=",
    "-project="+os.path.dirname(scriptpath),
    "-include="+include_path,
    "-binarize="+binarize_path
  ]

  if os.path.exists(packonly_path):
    args.append("-packonly")
    print("  (.PACKONLY detected, copying directly.)")

  """
  These seem to be bugged, so you will just have to copy CfgConvert, FileBank and DSSignFile
  to your Arma 3 root directory.

  "-cfgconvert="+convert_path,
  "-filebank="+filebank_path
  """

  if privatekey != "":
    args.append("-sign="+privatekey)
    #args.append("-dssignfile="+signfile_path)

  job = subprocess.Popen(args, shell=False, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
  out, error = job.communicate()

  if movemanually:
    job.wait()
    print("# Binarization of "+module_name+" complete; moving to destination.")

    # Delete previous pbo at that location
    try:
      os.remove(final_path)
    except:
      pass

    # Try to move the file
    try:
      shutil.move(temp_path, final_path)
    except:
      print("# Failed to move "+module_name+".")
    else:
      print("# "+module_name+" moved successfully.")


def main():
  # Check all paths.

  try:
    path = get_arma_path()
    assert(path != "")
  except:
    print("ERROR: Failed to get Arma installation path.\n")
    if getattr(sys, "frozen", False):
      quit = input("\nPress any key to exit ...")
    sys.exit(1)

  try:
    path = get_armatools_path()
    assert(path != "")
  except:
    print("ERROR: Failed to get Addon Builder installation path.\n")
    if getattr(sys, "frozen", False):
      quit = input("\nPress any key to exit ...")
    sys.exit(1)

  try:
    modules = get_modules()
  except:
    print("ERROR: Failed to read modules.\n")
    if getattr(sys, "frozen", False):
      quit = input("\nPress any key to exit ...")
    sys.exit(1)

  try:
    path = os.path.join(moddir if bool(moddir) else get_arma_path(), modfolder, "Addons")
    if not os.path.exists(path):
      print("# Creating Modfolder...")
      os.makedirs(path)
  except:
    print("ERROR: Failed to get/create mod path.")
    if getattr(sys, "frozen", False):
      quit = input("\nPress any key to exit ...")
    sys.exit(1)

  # Copy FileBank, CfgConvert and DSSignFile if necessary
  if getattr(sys, "frozen", False):
    convert_path      = os.path.join(get_arma_path(), "CfgConvert", "CfgConvert.exe")
    filebank_path     = os.path.join(get_arma_path(), "FileBank", "FileBank.exe")
    signfile_path     = os.path.join(get_arma_path(), "DSSignFile", "DSSignFile.exe")
    if not (os.path.exists(convert_path) and os.path.exists(filebank_path) and os.path.exists(signfile_path)):
      print("# SETUP")
      print("This seems to be the first time you're running this. We need to copy some folders (CfgConvert, FileBank, DSSignFile) from 'Arma 3 Tools' to 'Arma 3' to make this work. Are you ok with that? (y/n)")
      if (input("> ").lower() == "y"):
        if not os.path.exists(convert_path):
          try:
            shutil.copytree(os.path.join(get_armatools_path(), "CfgConvert"), os.path.join(get_arma_path(), "CfgConvert"))
          except:
            print("ERROR: Failed to copy CfgConvert from Arma 3 Tools to Arma 3. Please do that manually and restart.")
            print("\nPress any key to exit ...")
            sys.exit(1)
        if not os.path.exists(filebank_path):
          try:
            shutil.copytree(os.path.join(get_armatools_path(), "FileBank"), os.path.join(get_arma_path(), "FileBank"))
          except:
            print("ERROR: Failed to copy FileBank from Arma 3 Tools to Arma 3. Please do that manually and restart.")
            print("\nPress any key to exit ...")
            sys.exit(1)
        if not os.path.exists(signfile_path):
          try:
            shutil.copytree(os.path.join(get_armatools_path(), "DSSignFile"), os.path.join(get_arma_path(), "DSSignFile"))
          except:
            print("ERROR: Failed to copy DSSignFile from Arma 3 Tools to Arma 3. Please do that manually and restart.")
            print("\nPress any key to exit ...")
            sys.exit(1)

        print("All folders moved successfully.")
        print("")
      else:
        quit = input("\nPress any key to exit ...")
        sys.exit(1)


  # Binarize stuff.

  print("######################################################")
  print("# Tools found, starting binarization.                #")
  print("######################################################")

  threads = []

  print("\nModules that need binarization:")
  if (len(modules) > 0):
    print(", ".join(modules))
    print("")
  else:
    print("none.")

  for module in modules:
    print("# Binarizing: " + module)
    thread = threading.Thread(target=binarize, args=[module])
    thread.start()
    threads.append(thread)
    time.sleep(1) # give the threads some time, so they don't access include.txt at the same time etc.

  for thread in threads:
    thread.join()

  print("\n######################################################")
  print("# Binarization complete.                             #")
  print("######################################################")

  # Convert PBO names to lowercase for linux.
  path = os.path.join(moddir if bool(moddir) else get_arma_path(), modfolder, "Addons")
  for filename in os.listdir(path):
    try:
      os.rename(os.path.join(path, filename), os.path.join(path, filename.lower()))
    except:
      pass

  if getattr(sys, "frozen", False):
    quit = input("\nPress any key to exit ...")


if __name__ == "__main__":
  main()
