#!/usr/bin/env python3

# DESCRIPTION
# Build script for binarizing the entirety of a multi-PBO
# project without the mind-numbing chore of confirming 20
# different things.

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

PROJECTNAME = "AGM"
AUTHORS = ["KoffeinFlummi", "sutt0n"]

class Binarizer:
  def __init__(self, path):
    self.scriptpath = path
    self.modules = self.get_modules()
    self.paths = {}
    self.paths["privatekey"] = ""
    self.paths["arma"] = self.get_arma_path()
    self.paths["armatools"] = self.get_armatools_path()
    self.paths["moddir"] = self.get_arma_path()
    self.paths["modfolder"] = "@{}_dev".format(PROJECTNAME.lower())
    if getattr(sys, "frozen", False):
      self.prompt_paths()

  def prompt_paths(self):
    path_prompts = {
      "privatekey": "Path to .biprivatekey file. If not provided, addon will not be signed.",
      "arma": "Path to Arma installation. If not provided, registry value will be used.",
      "armatools": "Path to Arma tools installation. If not provided, registry value will be used.",
      "moddir": "Path to mod directory. If not provided, Arma path will be used.",
      "modfolder": "Name of mod folder. If not provided, @[project]_dev will be used."
    }
    for k, v in path_prompts.items():
      print("")
      print(v)
      inp = input("> ")
      if inp != "":
        self.paths[k] = inp

  def get_modules(self):
    if len(sys.argv) > 1:
      return sys.argv[1:]

    # Nothing was specifed, binarize all new PBOs.
    root = os.path.dirname(self.scriptpath)
    modules = []
    for module in os.listdir(root):
      if module[0] != "." and \
          os.path.isdir(os.path.join(root, module)) and \
          self.check_for_changes(module) and \
          not os.path.exists(os.path.join(root, module, ".DONTPACK")):
        modules.append(module)

    return modules

  def get_obsolete(self):
    destination_path = os.path.join(
      self.paths["moddir"], self.paths["modfolder"], "addons")

    pbos = list(map(lambda x: x.lower(),
      os.listdir(destination_path)))
    projects = list(map(lambda x: x.lower(),
      os.listdir(os.path.dirname(self.scriptpath))))

    obsolete = []
    for pbo in pbos:
      if not pbo.split(".")[0] in projects:
        obsolete.append(pbo)

    return obsolete

  def get_arma_path(self):
    try:
      reg = winreg.ConnectRegistry(None, winreg.HKEY_LOCAL_MACHINE)
      key = winreg.OpenKey(reg,
              r"SOFTWARE\Wow6432Node\bohemia interactive\arma 3")
      return winreg.EnumValue(key,1)[1]
    except:
      return ""

  def get_armatools_path(self):
    try:
      reg = winreg.ConnectRegistry(None, winreg.HKEY_LOCAL_MACHINE)
      key = winreg.OpenKey(reg,
              r"SOFTWARE\Wow6432Node\bohemia interactive\addonbuilder")
      return os.path.dirname(winreg.EnumValue(key,0)[1])
    except:
      return ""

  def folder_mod_time(self, path):
    if not os.path.isdir(path):
      return os.path.getmtime(path)

    maximum = os.path.getmtime(path)
    for thingy in os.listdir(path):
      maximum = max([self.folder_mod_time(
        os.path.join(path, thingy)), maximum])

    return maximum

  def check_for_changes(self, module_name):
    try:
      pbo_path     = os.path.join(
        self.paths["moddir"], self.paths["modfolder"], "Addons", module_name.lower()+".pbo")
      project_path = os.path.join(
        os.path.dirname(self.scriptpath), module_name)
      return self.folder_mod_time(project_path) > os.path.getmtime(pbo_path)
    except:
      return True

  def remove_obsolete(self):
    obsolete = self.get_obsolete()
    if len(obsolete) == 0:
      return False

    print("Removing obsolete PBOs:")
    print(", ".join(obsolete))
    for pbo in obsolete:
      try:
        os.remove(os.path.join(self.paths["moddir"], self.paths["modfolder"], "addons", pbo))
      except:
        print("ERROR: Failed to remove %s." & (pbo))

  def binarize_module(self, module_name):
    tempfolder       = os.path.join(os.environ["USERPROFILE"], "AppData", "Local", "Temp") # hardcoded, but who cares?
    addonbuilderpath = os.path.join(self.paths["armatools"], "AddonBuilder", "AddonBuilder.exe")
    sourcepath       = os.path.join(os.path.dirname(self.scriptpath), module_name)
    destinationpath  = os.path.join(self.paths["moddir"], self.paths["modfolder"], "addons")
    includepath      = os.path.join(os.path.dirname(self.scriptpath), "include.txt")
    finalpath        = os.path.join(destinationpath, module_name+".pbo")
    packonlypath     = os.path.join(sourcepath, ".PACKONLY")

    args = [
      addonbuilderpath,
      sourcepath,
      os.path.join(os.path.dirname(self.scriptpath), ".build"),
      "-prefix=",
      "-project="+os.path.dirname(self.scriptpath),
      "-include="+includepath
    ]

    if os.path.exists(packonlypath):
      args.append("-packonly")
      print("  (.PACKONLY detected, copying directly.)")

    if self.paths["privatekey"] != "":
      args.append("-sign="+self.paths["privatekey"])

    job = subprocess.Popen(args, shell=False, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    out, error = job.communicate()

    try:
      shutil.move(
        os.path.join(
          os.path.dirname(self.scriptpath), ".build", module_name+".pbo"),
        os.path.join(destinationpath, module_name.lower()+".pbo")
        )
    except:
      print("  FAILED to move {} to modfolder.".format(module_name))

    if self.paths["privatekey"] != "":
      if os.path.exists(packonlypath):
        bisignlocation = os.path.join(os.path.dirname(self.scriptpath),
          ".build")
      else:
        bisignlocation = os.path.join(tempfolder, PROJECTNAME)
      bisignlocation = os.path.join(bisignlocation,
        module_name+".pbo."+PROJECTNAME+".bisign")
      try:
        shutil.move(
          bisignlocation,
          os.path.join(destinationpath, module_name.lower()+".pbo."+PROJECTNAME.lower()+".bisign")
          )
      except:
        print("  FAILED to move {}'s signature to modfolder.".format(module_name))

  def check_paths(self):
    assert self.paths["arma"] != ""
    assert self.paths["armatools"] != ""
    assert self.paths["moddir"] != ""
    assert self.paths["modfolder"] != ""

  def binarize(self):
    modules = self.get_modules()
    threads = []

    print("Modules that need binarization:")
    if (len(modules) > 0):
      print(", ".join(modules))
      print("")
    else:
      print("none.")

    for module in modules:
      print("# Binarizing: " + module)
      thread = threading.Thread(target=self.binarize_module, args=[module])
      thread.start()
      threads.append(thread)
      time.sleep(1) # give the threads some time, so they don't access include.txt at the same time etc.

    for thread in threads:
      thread.join()

    try:
      shutil.rmtree(os.path.join(os.path.dirname(self.scriptpath), ".build"))
    except:
      pass

    return len(modules)

  def verify(self):
    newmodules = self.get_modules()
    if len(newmodules) == 0:
      return 0
    else:
      print("\nThe following modules failed to binarize:")
      print(", ".join(newmodules))
      return len(newmodules)

def main():
  if getattr(sys, "frozen", False):
    scriptpath = os.path.dirname(sys.executable)
  else:
    scriptpath = os.path.realpath(__file__)

  print("{} Binarizer".format(PROJECTNAME))
  print("Authors: {}".format(", ".join(AUTHORS)))
  b = Binarizer(scriptpath)

  try:
    b.check_paths()
  except:
    print(" Failed to get tool paths. ".center(79, "="))
    print("")
    raise

  print("")
  print(" Tools found, binarizing. ".center(79, "="))
  print("")

  b.remove_obsolete()
  attempted = b.binarize()

  failed = b.verify()
  succeeded = attempted - failed

  result = " {} / {} modules binarized. ".format(succeeded, attempted)
  print("")
  print(result.center(79, "="))

  if getattr(sys, "frozen", False):
    input("\nPress any key to exit...\n")

  if failed > 0:
    sys.exit(1)

if __name__ == "__main__":
  main()
