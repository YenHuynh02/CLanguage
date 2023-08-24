/*******************************************************************
* Student Name: Yen Huynh
* Student Number: 041068712
* Course: 23S_CST8234
* Declaration: This class uses to display the overall score of each student
* This is my own original work except where sources have been cited.
*******************************************************************/

#ifndef STUDENTS_H
#define STUDENTS_H

struct student {
    int studentID;
    double percentMark;
};

int compareStuID(const void *a, const void *b);
int compareMark(const void *a, const void *b);
void convertMark(double score);
int readFile(const char *filename, struct student *students, int maxStu);
void printStudents(const struct student *students, int numberOfStu);
double findMedian(const struct student *students, int numberOfStu);
double findAverage(const struct student *students, int numberOfStu);
#endif