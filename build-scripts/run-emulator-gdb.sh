#!/usr/bin/env bash

# edit the path to your emulator
# emulator can be with gui too - keep in mind when you exit the app, the emulator keeps running -> you have to exit it manually every time
# there is a cli (citra.exe or citra instead of citra-qt) program that would boot the program directly - this approach would be preferred
emulator="/usr/bin/citra"
dir="cmake-build-debug"
# should be same port as in "Remote Debug" run configuration
port="1234"

shopt -s nullglob
files=("$dir"/*.3dsx)

case "${#files[@]}" in
  0)
    echo "Error: no .3dsx files found in '$dir'" >&2
    exit 1
    ;;
  1)
    exec $emulator -g "$port" "${files[0]}"
    ;;
  *)
    echo "Error: more than one .3dsx file found in '$dir':" >&2
    printf '  %s\n' "${files[@]}" >&2
    echo "HINT: delete stale artefacts" >&2
    exit 1
    ;;
esac
