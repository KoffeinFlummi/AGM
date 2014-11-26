#!/usr/bin/env python3

import os
import sys
import re

# CODING GUIDELINE CHECK
# Author: KoffeinFlummi
# ----------------------
# https://github.com/KoffeinFlummi/AGM/wiki/Coding-Guidelines

# USAGE
# -----
# To only check a specific module, put it down as a sys arg.
# By default, everything is checked.
# Use "-f" to attempt automatic fixes
# Use "-q" to surpress file information and just show module stuff

# Right now it just checks indentation, might expand on it later

def colorize(text, color):
  try:
    import xtermcolor
    print(xtermcolor.colorize(text, rgb=color))
  except:
    print(text)

def get_all_modules(path):
  modules = []
  for m in os.listdir(path):
    if os.path.isdir(os.path.join(path,m)) and m[0] != ".":
      modules.append(m)
  return modules

def check_file(projectpath, path, name):
  path = os.path.join(path, name)
  relative = os.path.relpath(path, projectpath)

  # skip non-text files
  if name.split(".")[-1] not in ["sqf", "hqf", "cpp", "xml"]:
    return 0, 0

  if "-q" not in sys.argv:
    print("\nCHECKING FILE: {}".format(relative))

  fhandle = open(path, "r")
  content = fhandle.read()
  fhandle.close()

  errors = 0
  warnings = 0

  numtabs = content.count("\t")
  if numtabs > 0:
    errors += numtabs
    if "-q" not in sys.argv:
      print("  ERROR: Detected {} tab(s)".format(numtabs))
      print("         Please use 2 spaces for indentation instead.")

    if "-f" in sys.argv:
      fhandle = open(path, "w")
      content = content.replace("\t", "  ")
      while content.count(" \n") > 0:
        content = content.replace(" \n", "\n")
      fhandle.write(content)
      fhandle.close()
      if "-q" not in sys.argv:
        print("  !!! Attempted to fix indentation. Please check to confirm results.")

  classdefs = []
  # broken ATM
  #if name.split(".")[-1] == "cpp":
  #  classdefs = re.findall(r"class(.*?)\{", content, re.DOTALL)
  for c in classdefs:
    if re.match(r" [a-zA-Z0-9\-_#]+(: [a-zA-Z0-9\-_#]+)? ", c) is None:
      warnings += 1
      if "-q" not in sys.argv:
        print("  WARNING: Malformed class definition at:")
        print("           class{}{{".format(c.split("\n")[0]))

  if warnings + errors == 0 and "-q" not in sys.argv:
    string = "No problems detected. Good job!"
    colorize(string, 0x00FF00)
  elif "-q" not in sys.argv:
    string = "There are some issues, please resolve them and rerun this script."
    colorize(string, 0xFF0000)

  return warnings, errors

def check_module(projectpath, module):
  #print("")
  print(" Checking {} ".format(module).center(79, "="))

  warnings = 0
  errors = 0
  root = os.path.join(projectpath, module)
  for path, subdirs, files in os.walk(root):
    for name in files:
      warn, err = check_file(projectpath, path, name)
      warnings += warn
      errors += err

  if warnings + errors == 0:
    string = "\n{}: NO PROBLEMS".format(module)
    colorize(string, 0x00FF00)
  else:
    string = "\n{}: THERE WERE {} ERROR(S) AND {} WARNING(S)".format(module, errors, warnings)
    colorize(string, 0xFF0000)

def main():
  scriptpath = os.path.realpath(__file__)
  projectpath = os.path.dirname(os.path.dirname(scriptpath))

  print("##########################")
  print("# Coding Guideline Check #")
  print("##########################\n")

  modules = get_all_modules(projectpath)
  if len(sys.argv) > 1 and sys.argv[1] in modules:
    modules = [sys.argv[1]]

  for m in modules:
    check_module(projectpath, m)
    print("")

if __name__ == "__main__":
  main()
