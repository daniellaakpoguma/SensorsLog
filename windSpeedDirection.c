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
 * Function to wind speed and direction log data in array
*/
void processWindSDData(struct WindSpeedAndDirection windArray[], int* windCount, time_t timestamp, int type, int kmPerH,double degrees ) {
    struct WindSpeedAndDirection wind; // creates new instance of struct
    // storing individuals values
    wind.Timestamp = timestamp;
    wind.Type = type;
    wind.KmPerH = kmPerH;
    wind.Degrees = degrees;
           
    windArray[*windCount] = wind;  // adding to array
    (*windCount)++;

}

/**
 * Function to print Log
*/
void printWindSDLog (struct WindSpeedAndDirection windArray[],int* windCount){
    printf("Wind Speed and Direction Log:\n");
    printf("Date\t\tTime\t\tSpeed\tDirection\n");
    for (int i = 0; i < *windCount; i++) {
        char dateBuff[11]; // Buffer to store the date (YYYY-MM-DD)
        char timeBuff[9]; // Buffer to store the time (HH:MM:SS)

        strftime(dateBuff, sizeof(dateBuff), "%Y-%m-%d", localtime(&windArray[i].Timestamp));
        strftime(timeBuff, sizeof(timeBuff), "%H:%M:%S", localtime(&windArray[i].Timestamp));
        printf("%s\t%s\t%.2lf\t%d\n", dateBuff, timeBuff, windArray[i].KmPerH, windArray[i].Degrees);
    }
    printf("\n");
}