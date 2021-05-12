For this homework, you will be making a shell script (using whichever shell you prefer).
● The script will be named cal (followed by the appropriate suffix for the shell, .sh, .csh, .ksh, or
.bash).
● The script takes two command line parameters. The first indicates a month, and should be a
number between 1 and 12.
● Alternatively, you could also accept a string value, such as 'Jan', 'Feb', and so on.
● The second parameter indicates a year. Typically the value would be a 4-digit number.
● Alternatively, if the number is a two-digit number (or 1 digit number), you could add 2000 to the
number, so given 21, the script would consider this to be 2021.
● The script will output a calendar for the month, as follows:

This program similar to cal utility in unix terminal

Run the program by bash cal.bash <month> <year>
  
❯ bash cal.bash Jun 1995
      June, 1995
 Su Mo Tu We Th Fr Sa
              1  2  3
  4  5  6  7  8  9 10
 11 12 13 14 15 16 17
 18 19 20 21 22 23 24
 25 26 27 28 29 30% 
