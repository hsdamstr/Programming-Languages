#!/bin/sh
DoExitAsm ()
{ echo "An error occurred while assembling $1"; exit 1; }
DoExitLink ()
{ echo "An error occurred while linking $1"; exit 1; }
echo Assembling func
/usr/bin/as --64 -o input/1.func.o   input/1.func.s
if [ $? != 0 ]; then DoExitAsm func; fi
echo Linking input/1.func
OFS=$IFS
IFS="
"
/usr/bin/ld.bfd -b elf64-x86-64 -m elf_x86_64     -s  -L. -o input/1.func -T link32591.res -e _start
if [ $? != 0 ]; then DoExitLink input/1.func; fi
IFS=$OFS
