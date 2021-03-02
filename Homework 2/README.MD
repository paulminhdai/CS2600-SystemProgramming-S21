## Column Sorter
This program will require one command line parameter, the number of a column. This program will read input data on ​stdin​, saving each line it reads in a list. It will then sort the list based on the values in the indicated column, then it will write all of the data out to ​stdout​.


The input data should be in the form of CSV (comma-separated-value). Each line can be divided into a number of columns, being split at commas. We have a couple of simplifications here, just to make this problem a little more manageable:
1. Every line has the same number of columns
2. All of the entries are simple values, integers or words. The text values aren't quoted, and there are no commas inside a value.


Here is a short example of some input:
* Sam,15,banana
* Julie,23,grape
* Scott,12,kiwi

If the program was asked to sort by column 1 (the names), the output would be: 
* Julie,23,grape
* Sam,15,banana
* Scott,12,kiwi

Your program should use at least one structure, and should have at least a couple of functions.
