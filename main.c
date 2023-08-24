/*******************************************************************
* Student Name: Yen Huynh
* Student Number: 041068712
* Course: 23S_CST8234
* Declaration: This class uses to display the overall score of each student
* This is my own original work except where sources have been cited.
*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "students.h"

int main(int argc, char *argv[]) {
    char *filename;
    double median, average;

    /*Read 100 students inside the file*/
    struct student students[100];
    int numStudents;

    /*If an argument count is not equal to 2, return error*/
    if (argc != 2) {
        printf("Only two argument allowed.\n");
        return 1;
    }
    
    /*Only allow one file name*/
    filename = argv[1];

    numStudents = readFile(filename, students, 100);

    /*Cannot read the file*/
    if (numStudents == -1) {
        return 1;
    }

    /*Sort the student ID to display in order*/
    qsort(students, numStudents, sizeof(struct student), compareStuID);
    printStudents(students, numStudents);

    /*Sort the student mark to find the median and average*/
    qsort(students, numStudents, sizeof(struct student), compareMark);
    median = findMedian(students, numStudents);
    average = findAverage(students, numStudents);

    /*Print the median and average mark*/
    printf("Median Percent Mark: %.2f\n", median);
    printf("Average Percent Mark: %.2f\n", average);
    printf("Program by Yen Huynh\n");
    return 0;
}
