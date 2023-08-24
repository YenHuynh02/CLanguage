/*******************************************************************
* Student Name: Yen Huynh
* Student Number: 041068712
* Course: 23S_CST8234
* Declaration: This class uses to display the overall score of each student
* This is my own original work except where sources have been cited.
*******************************************************************/

#include <stdio.h>
#include "students.h"

int i;
int compareStuID(const void *a, const void *b) {
    const struct student *stuA = (const struct student *)a; /*Pointer to the parameter to assign the studentID*/
    const struct student *stuB = (const struct student *)b; /*Pointer to the parameter to assign the studentID*/
    
    /*Student A go before student B*/
    if(stuA->studentID < stuB->studentID) {
        return -1;
    }

    /*Student A go after student B*/
    if(stuA->studentID > stuB->studentID) {
        return 1;
    }
    return 0; /*Considered equal*/
}

int compareMark(const void *a, const void *b) {
    const struct student *stuA = (const struct student *)a; /*Pointer to the parameter to assign the percentMark*/
    const struct student *stuB = (const struct student *)b; /*Pointer to the parameter to assign the percentMark*/

    /*Student A percentage mark less than student B*/
    if(stuA->percentMark < stuB->percentMark) {
        return -1;
    }

    /*Student A percentage mark greater than student B*/
    if(stuA->percentMark > stuB->percentMark) {
        return 1;
    }
    return 0; /*Considered equal*/
}

/*Check the percentage mark depends on the score student get*/
void convertMark(double score) {
    if(score >= 90) {printf("A+");}
    else if(score >= 85) {printf("A");}
    else if(score >= 80) {printf("A-");}
    else if(score >= 77) {printf("B+");}
    else if(score >= 73) {printf("B");}
    else if(score >= 70) {printf("B-");}
    else if(score >= 67) {printf("C+");}
    else if(score >= 63) {printf("C");}
    else if(score >= 60) {printf("C-");}
    else if(score >= 57) {printf("D+");}
    else if(score >= 53) {printf("D");}
    else if(score >= 50) {printf("D-");}
    else {printf("F");}
}

int readFile(const char *filename, struct student *students, int maxStu) {
    int count;
    FILE *file = fopen(filename, "rb"); /*Read binary of the .dat file*/
    if (!file) {
        printf("Error! Cannot open the file\n");
        return -1;
    }

    /*
    * Check how many value it read
    * Parameters:
    * students: pointer to a block of memory with a minimum size of size*maxStu bytes.
    * (struct student): size in bytes of each element to be read.
    * maxStu: number of elements, each one with a size of size bytes.
    * file: pointer to a FILE object that specifies an input stream.
    */
    count = fread(students, sizeof(struct student), maxStu, file);
    fclose(file);
    return count;
}

/*This method uses to print the student data*/
void printStudents(const struct student *students, int numberOfStu) {
    printf("Student Data Sorted by studentID: \n");
    for (i = 0; i < numberOfStu; i++) {
        printf("Student ID: %d, Percent Mark: %6.2f, Letter Grade: ", 
        students[i].studentID, 
        students[i].percentMark); 
        convertMark(students[i].percentMark);
        printf("\n");
    }
}

/*This method uses to find the median of the percent mark*/
double findMedian(const struct student *students, int numberOfStu) {
    if (numberOfStu % 2 == 0) {
        /*If it's even number, the median is the average of the two middle data points in the list. */
        return (students[(numberOfStu / 2) - 1].percentMark + students[(numberOfStu / 2)].percentMark) / 2;
    }

    else {
        /*If it's odd number, the median is the middle data point in the list*/
        return students[numberOfStu / 2].percentMark;
    }
}

/*This method uses to find the average of the percent mark*/
/*Algorithm: 
* Total of average = all of the student percent mark / the total of the student
*/
double findAverage(const struct student *students, int numberOfStu) {
    double total = 0.0;
    for (i = 0; i < numberOfStu; i++) {
        total += students[i].percentMark; 
    }
    return total / numberOfStu;
}