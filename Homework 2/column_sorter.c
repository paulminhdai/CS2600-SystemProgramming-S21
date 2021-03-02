/*
 * Who: Paul (Dai) Vuong
 * When: March 2, 2021
 * Why: Homeword 2 - Column Sorter
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
  char name[100];
  int number;
  char fruit[100];
};

const int SIZE = 10;
struct Data data_list[SIZE]; // initialize an array will contain the data

/* 
 * Read data from csv file and store them in struct array
 */
void read_store_data() {
    size_t string_len = 100;
    char *buff = malloc(string_len);

    FILE *csvFile;
    csvFile = fopen("data.csv", "r"); // open file

    // error occurs if cannot read file
    if (csvFile == NULL) {
        printf("Failed to open the file.");
        exit(1);
    }

    // loop through the struct array
    int i = 0;
    while(fgets(buff, string_len, csvFile) != NULL) {
        if ((strlen(buff)>0) && (buff[strlen (buff) - 1] == '\n'))
            buff[strlen (buff) - 1] = '\0'; 
        // copy data line by line  to struct
        char *temp;
        temp = strtok(buff, ", \n");
        strcpy(data_list[i].name, temp);
        temp = strtok(NULL, ", \n");
        data_list[i].number = atoi(temp);
        temp = strtok(NULL, ", \n");
        strcpy(data_list[i].fruit, temp);

        i++;
    }

    fclose(csvFile); // close the file
}

/*
 * Print out the struct list
 */
void print_list() {
    for(int i = 0; i<10; i++) {
        printf("%10s  %4d  %10s\n", data_list[i].name, data_list[i].number, data_list[i].fruit);
    }
}

/*
 * Bubble sort 
 */
void bubble_sort(int col, int arr_size) {
    struct Data tmp;
    
    switch(col) {
        case 1: // sort by column 1
            for(int i = 0; i < arr_size-1; i++) {
                for(int j = 0; j < arr_size - i - 1; j++) {
                    if(strcmp(data_list[j].name, data_list[j+1].name) > 0) {
                        tmp = data_list[j];
                        data_list[j] = data_list[j+1];
                        data_list[j+1] = tmp;
                    }
                }
            }
            break;
        case 2: // sort by column 2
            for(int i = 0; i < arr_size-1; i++) {
                for(int j = 0; j < arr_size - i - 1; j++) {
                    if(data_list[j].number > data_list[j+1].number) {
                        tmp = data_list[j];
                        data_list[j] = data_list[j+1];
                        data_list[j+1] = tmp;
                    }
                }
            }
            break;
        case 3: // sort by column 3
            for(int i = 0; i < arr_size-1; i++) {
                for(int j = 0; j < arr_size - i - 1; j++) {
                    if(strcmp(data_list[j].fruit, data_list[j+1].fruit) > 0) {
                        tmp = data_list[j];
                        data_list[j] = data_list[j+1];
                        data_list[j+1] = tmp;
                    }
                }
            }
            break;
    }
}

/*
 * Insertion sort 
 */
void insertion_sort(int col, int arr_size) {
    struct Data tmp;
    switch (col) {
    case 1: // sort by column 1
        for(int i = 1; i < arr_size; i++) {
            tmp = data_list[i];
            int j = i - 1;
            while(j >= 0 && strcmp(data_list[j].name, tmp.name) > 0) {
                data_list[j+1] = data_list[j];
                j -= 1;
            }
            data_list[j+1] = tmp;
        }
        break;
    
    case 2: // sort by column 2
        for(int i = 1; i < arr_size; i++) {
            tmp = data_list[i];
            int j = i - 1;
            while(j >= 0 && data_list[j].number > tmp.number) {
                data_list[j+1] = data_list[j];
                j -= 1;
            }
            data_list[j+1] = tmp;
        }
        break;
    
    case 3: // sort by column 3
        for(int i = 1; i < arr_size; i++) {
            tmp = data_list[i];
            int j = i - 1;
            while(j >= 0 && strcmp(data_list[j].fruit, tmp.fruit) > 0) {
                data_list[j+1] = data_list[j];
                j -= 1;
            }
            data_list[j+1] = tmp;
        }
        break;
    }   
}

int main(int argc, char *argv[]) {
    // help info from command line 
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        printf("Run this program by run ./column_sorter <col#> <sort_option>, where:\n");
        printf("\t- col# is 1, 2, or 3, as 3 columns from the data.\n");
        printf("\t- sort_option is 1: buble sort or 2: insection sort.\n");
        return 0;
    }

    // catch if user passes wrong number of params in command line
    if (argc != 3) {
        printf("ERROR! Unvalid command. Enter ./column_sorter <col#> <sort_option>\n");
        return 0;
    }

    int picked_column = atoi(argv[1]); // picked column from command line param
    int sort_option = atoi(argv[2]); // picked sort algorithm
    
    // catch if user passes wrong params in command line
    if ((picked_column < 1 || picked_column > 3) || (sort_option < 1 || sort_option > 2)) {
        printf("ERROR! Unvalid parameters. Enter ./column_sorter <col#> <sort_option>\n");
        return 0;
    }

    read_store_data(); // Read and store data from csv file
    printf("The Original Data\n");
    print_list(); // print struct array 

    // sort struct array by column number with 2 sorting algorithms
    switch (sort_option) {
    case 1:
        printf("\nSorting by the bubble sort algorithm...\n");
        bubble_sort(picked_column, SIZE);
        break;
    
    case 2:
        printf("\nSorting by the insertion sort algorithm...\n");
        insertion_sort(picked_column, SIZE);
        break;
    }
      
    printf("\nThe Data After Sort By Column %d\n", picked_column);
    print_list(); // print struct array 
    return 0;
}
