#!/usr/bin/env python


##############################################################
# Authors: KoffeinFlummi, sutt0n                             #
#                                                            #
# Build script for binarizing the entirety of a multi-PBO    #
# project without the mind-numbing chore of comfirming 20    #
# fucking things.                                            #
#                                                            #
# This thing is WIP and for now you need to copy some        #
# folders from Arma 3 Tools to Arma 3 for it to work         #
# (CfgConvert, FileBank, Binarize, DSSignFile).              #
#                                                            #
# By default all PBOs that have modifications since the last #
# binarization are binarized. You can also start the script  #
# with the PBOs you want to binarized as arguments.          #
# e.g.: python binarizer.py AGM_Core AGM_Resting             #
##############################################################


import os
import sys
import shutil
import subprocess
import winreg
import threading
import time

# Path to .biprivatekey file. If not set, addon will not be signed.
privatekey   = ""#D:\\Programme\\Steam\\SteamApps\\common\\Arma 3 Tools\\AGM.biprivatekey" # if set to anything other that "" it will sign the addons

# Path to Arma installation. If not set, registry values will be used.
arma         = ""

# Path to Arma tools. If not set, registry values will be used.
armatools    = ""

# Path to mod storage. If not set, Arma 3 directory will be used. Not including modfolder.
moddir       = ""

# Name of the mod folder. REQUIRED!
modfolder    = "@AGM_dev"

# set this to false once bohemia fixes their stuff and you don't need to manually move files from temp anymore
movemanually = True

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
  return winreg.EnumValue(key,0)[1]

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
    pbo_path     = os.path.join(get_arma_path(), modfolder, "Addons", module_name+".pbo")
    project_path = os.path.join(os.path.dirname(os.path.realpath(__file__)), module_name)
    return folder_mod_time(project_path) > os.path.getmtime(pbo_path)
  except: # File not found or some other weirdness
    return True

def get_modules():
  """ Get all the folders that need binarization """

  # User manually defined modules to be binarized, use those.
  if len(sys.argv) > 1:
    return sys.argv[1:]

  # Nothing was specifed, binarize all new PBOs.
  root = os.path.dirname(os.path.realpath(__file__))
  modules = []
  for module in os.listdir(root):
    if module[0] != "." and os.path.isdir(os.path.join(root, module)) and check_for_changes(module):
      modules.append(module)
  return modules

def binarize(module_name):
  """ Binarizes the given module """
  global modfolder, privatekey, movemanually

  tempfolder        = os.path.join(os.environ["USERPROFILE"], "AppData", "Local", "Temp") # hardcoded, but who cares?

  addonbuilder_path = os.path.join(get_armatools_path(), "AddonBuilder.exe")
  source_path       = os.path.join(os.path.dirname(os.path.realpath(__file__)), module_name)
  destination_path  = os.path.join(get_arma_path(), modfolder, "Addons")
  include_path      = os.path.join(os.path.dirname(os.path.realpath(__file__)), "include.txt")
  temp_path         = os.path.join(tempfolder, module_name+".pbo")
  final_path        = os.path.join(destination_path, module_name+".pbo")

  binarize_path     = os.path.join(get_armatools_path(), "Binarize", "binarize.exe")
  convert_path      = os.path.join(get_armatools_path(), "CfgConvert", "CfgConvert.exe")
  filebank_path     = os.path.join(get_armatools_path(), "FileBank", "FileBank.exe")
  signfile_path     = os.path.join(get_armatools_path(), "DSSignFile", "DSSignFile.exe")

  args = [
    addonbuilder_path,
    source_path,
    destination_path,
    "-prefix=",
    "-project="+os.path.dirname(os.path.realpath(__file__)),
    "-include="+include_path
  ]

  """
  These seem to be bugged, so you will just have to copy Binarize, CfgConvert, FileBank and DSSignFile
  to your Arma 3 root directory.

  "-cfgconvert="+convert_path,
  "-binarize="+binarize_path,
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


# Check all paths.

try:
  path = get_arma_path()
  assert(path != "")
except:
  print("ERROR: Failed to get Arma installation path.\n")
  sys.exit(1)

try:
  path = get_armatools_path()
  assert(path != "")
except:
  print("ERROR: Failed to get Addon Builder installation path.\n")
  sys.exit(1)

try:
  modules = get_modules()
except:
  print("ERROR: Failed to read modules.\n")
  sys.exit(1)

try:
  path = os.path.join(moddir if bool(moddir) else get_arma_path(), modfolder, "Addons")
  if not os.path.exists(path):
    print("# Creating Modfolder...")
    os.makedirs(path)
except:
  print("ERROR: Failed to get/create mod path.")
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
