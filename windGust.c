
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
#include <string.h>
#include "lab4.h"

/**
 * Function to store wind log data in array
*/
void processWindGustData(struct WindGust gustArray[], int* gustCount, time_t timestamp, int type, double prev ,double current ) {
    struct WindGust gust; // creates new instance of struct
    // storing individuals values
    gust.Timestamp = timestamp;
    gust.Type = type;
    gust.Prev = prev;
    gust.Current = current;
         
    gustArray[*gustCount] = gust; // adding to array
    (*gustCount)++;

}

/**
 * Function to check if wind gust is increasing, decreasing or unchanged
*/
void checkWindGustTrend(double prev, double current, char* status) {
    if (current > prev) { // checks if current is greater than previous
        strcpy(status, "Increasing");
    } else if (current < prev) {  // checks if current is less than previous
        strcpy(status, "Decreasing");
    } else if (current == prev){  // checks if current is same as previous
        strcpy(status, "Unchanged");
    }
}

/**
 * Function to print Log
*/
void printWindGustLog (struct WindGust gustArray[],int* gustCount){
    printf("Wind Gusts Log:\n");
    printf("Date\t\tTime\t\tWind Change\n");
     for (int i = 0; i < *gustCount; i++) {
     
        char dateBuff[11]; // Buffer to store the date (YYYY-MM-DD)
        char timeBuff[9]; // Buffer to store the time (HH:MM:SS) 
        
        strftime(dateBuff, sizeof(dateBuff), "%Y-%m-%d", localtime(&gustArray[i].Timestamp));
        strftime(timeBuff, sizeof(timeBuff), "%H:%M:%S", localtime(&gustArray[i].Timestamp));

        char gustStatus [20];
        checkWindGustTrend(gustArray[i].Prev, gustArray[i].Current, gustStatus); //calls gust status
        printf("%s\t%s\t%s\n", dateBuff,timeBuff, gustStatus);
    }
    printf("\n");
}