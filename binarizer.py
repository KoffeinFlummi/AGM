#!/usr/bin/env python


##############################################################
# Author: KoffeinFlummi                                      #
#                                                            #
# Build script for binarizing the entirety of a multi-PBO    #
# project without the mind-numbing chore of comfirming 20    #
# fucking things.                                            #
#                                                            #
# This thing is WIP and for now you need to copy some        #
# folders from Arma 3 Tools to Arma 3 for it to work         #
# (CfgConvert, FileBank, Binarize, DSSignFile).              #
##############################################################


import os
import sys
import subprocess
import winreg
import threading
import time

privatekey = "" # if set to anything other that "" it will sign the addons
modfolder  = "@AGM_dev"

def get_arma_path():
  """ Get the installation directory of Arma 3 """
  reg = winreg.ConnectRegistry(None, winreg.HKEY_LOCAL_MACHINE)
  key = winreg.OpenKey(reg, r"SOFTWARE\Wow6432Node\bohemia interactive\arma 3")
  return winreg.EnumValue(key,1)[1]

def get_armatools_path():
  """ Get the installation directory of the Arma 3 Tools """
  reg = winreg.ConnectRegistry(None, winreg.HKEY_LOCAL_MACHINE)
  key = winreg.OpenKey(reg, r"SOFTWARE\Wow6432Node\bohemia interactive\addonbuilder")
  return winreg.EnumValue(key,0)[1]

def get_modules():
  """ Get all the folders that need binarization """
  root = os.path.dirname(os.path.realpath(__file__))
  modules = []
  for module in os.listdir(root):
    if module[0] != "." and os.path.isdir(os.path.join(root, module)):
      modules.append(module)
  return modules

def binarize(module_name):
  """ Binarizes the given module """
  global modfolder, privatekey

  addonbuilder_path = os.path.join(get_armatools_path(), "AddonBuilder.exe")
  source_path       = os.path.join(os.path.dirname(os.path.realpath(__file__)), module_name)
  destination_path  = os.path.join(get_arma_path(), modfolder, "Addons")
  include_path      = os.path.join(os.path.dirname(os.path.realpath(__file__)), "include.txt")

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

  return subprocess.call(args)

try:
  path = get_arma_path()
  assert(path != "")
except:
  print("ERROR: Failed to get Arma installation path.")
  sys.exit(1)

try:
  path = get_armatools_path()
  assert(path != "")
except:
  print("ERROR: Failed to get Addon Builder installation path.")
  sys.exit(1)

try:
  modules = get_modules()
except:
  print("ERROR: Failed to read modules.")
  sys.exit(1)


print("\n######################################################")
print("# Tools found, starting binarization.                #")
print("######################################################\n")

threads = []

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
