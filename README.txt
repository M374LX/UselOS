UselOS
By M-374 LX <http://m374lx.users.sourceforge.net/>

About
-----
 UselOS, which stands for "useless operating system", is a small operating 
 system for x86 PCs I decided to write just to better understand how such type 
 of software works.

Basic usage
-----------
 When starting the operating system, you are presented with USH, the useless
 command shell, where you can enter commands.

USH commands
------------
 clear
  Arguments: none
  Clear the screen

 echo
  Arguments: strings to print
  Print a series of space-separated strings on the screen

 help
  Arguments: none
  Show a list of commands that can be entered

 reboot
  Arguments: none
  Reboot (reset) the system

Building
--------
 Building the operating system requires GNU C Compiler (GCC), GNU Assembler
 (AS), and GNU Make. You can build it by entering the "src" directory and
 running the command "make".

 After building, you can generate a bootable ISO image featuring the GRUB 
 bootloader by running "make iso". This requires the "grub-mkrescue" utility.

 To delete all files resulting from the build process, run "make clean".

Running
-------
 You can run the operating system on a PC without using an emulator by
 generating an ISO image (as seen in "Building"), burning it on a removable
 media (such as a CD or a USB stick) and then booting it.

 You can also run it on an emulator such as QEMU or Bochs.

Licensing
---------
 The code is in public domain, which means that you can use it freely.

