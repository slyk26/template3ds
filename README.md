# 3DS Development Template (CLion)

This repo is designed to be a "quick start" for developing homebrew apps for the 3ds on linux.

currently this is linux only, but I am open to PRs to make it work on Windows too!

## Features

* CLion run configurations to build and debug your app directly in citra/azahar
* breakpoints in sourcecode available via gdb
* no physical 3ds needed
* simple logging to gdb

## Prerequisites

* [devkitPro](https://devkitpro.org/wiki/Getting_Started) installed
* libctru installed
* DEVKITPRO env variable
* any of these emulators:
  * citra - preferably the "headless" version (without gui)
  * [azahar](https://azahar-emu.org/)

GUI version does work but it's annoying since stopping the homebrew app boots you back to the menu instead of quitting the emulator.

## post-clone TODOs

* rename project directory `template3ds` to your preferred app name
* `Load CMake Project` This should create:
  * cmake-build-debug
  * cmake-build-release
* execute `build_debug` to create `*.elf` for `connect_to_gdb`
* go to [run-emulator-gdb.sh](build-scripts/run-emulator-gdb.sh) and set `emulator=` path to your emulator.
* edit author, description and (optional) name of the homebrew app in [CMakeLists.txt](CMakeLists.txt)

## how to run

* run `Debug 'DebugApp'` (Bug Icon next to DebugApp) - your emulator should start with your homebrew app loaded!

## but I only want to build!

* `build_release` to create an optimized version
* artifacts (.3dsx) are found in [cmake-build-release](cmake-build-release)