/**
 * Student Name: Oghenerukevwe Akpoguma
 * Student Number: 0410756254
 * Course:CST8234 
 * Lab 4
 * Date: 10th July, 2023.
 * Lab Professor: David Houtman
 * This is my original work except where sources have been cited
 */

// inclusion files
#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"


/**
 * Function to store temp log data in array
*/
void processTempData(struct Temp tempArray[], int* tempCount, time_t timestamp, int type, double celsius) {
    struct Temp temp; // creates new instance of struct
    // storing individuals values
    temp.Timestamp = timestamp;
    temp.Type = type;
    temp.Celsius = celsius;
    
    tempArray[*tempCount] = temp;  // adding to array
    (*tempCount)++;
    
}

/**
 * Function to print Log
*/
void printTempLog (struct Temp tempArray[],int* tempCount){
    printf("Temperature Log:\n");
     printf("Date\t\tTime\t\tCelsius\n");
    for (int i = 0; i < *tempCount; i++) {
        char dateBuff[11]; // Buffer to store the date (YYYY-MM-DD)
        char timeBuff[9]; // Buffer to store the time (HH:MM:SS) 
        
        strftime(dateBuff, sizeof(dateBuff), "%Y-%m-%d", localtime(&tempArray[i].Timestamp));//formats string
        strftime(timeBuff, sizeof(timeBuff), "%H:%M:%S", localtime(&tempArray[i].Timestamp));//formats string
        printf("%s\t%s\t%.2lf\n", dateBuff, timeBuff, tempArray[i].Celsius);
    }
    printf("\n");
}