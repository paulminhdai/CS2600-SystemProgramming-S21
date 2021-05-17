For this homework, you will be making a shell script (using whichever shell you prefer).

● The script will be named move (followed by the appropriate suffix for the shell, .sh, .csh, .ksh, or
.bash).

● The script takes two command line parameters. The first is the name of a file on your system,
and the second is the new name for that file.

● The script will move the file (rename the file), so
$ move src.c dst.c
will rename the file 'src.c' to be 'dst.c'.

● Yes, this script will probably use the mv command to actually do the move.

● However, if there is already a file named dst.c (in this case), then the script will try the name
dst.c.1 instead. If there is already a file with that name, it will try the name dst.c.2, and so on, until it finds a unique name. It then performs the move.
