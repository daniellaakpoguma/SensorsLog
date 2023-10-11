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

// defining maximum size of array
#define MAX_SIZE 100


// Entry point of the application
int main() {

    // Arrays to store message types
    struct Temp tempArray[MAX_SIZE];
    struct WindSpeedAndDirection windArray[MAX_SIZE];
    struct WindGust gustArray[MAX_SIZE];

    // count for each array
    int tempCount = 0;
    int windCount = 0;
    int gustCount = 0;

    FILE *filePtr; //pointer to File
    filePtr = freopen(NULL, "r", stdin); // opening file and replacing with input stream

    if (filePtr == NULL) {
        printf("Failed to open file.\n");
        return 1; // Return non-zero to indicate an error
    }

    char buffer [255]; //temporary storage space for each line
    while (fgets(buffer, 255, filePtr) != NULL) {
        char* token = strtok(buffer, ","); // gettting token from line
        time_t timestamp = atoi(token); //converting to time_t and storing in timestamp

        token = strtok(NULL, ","); // gettting token from line
        int type = atoi(token); //converting to int and storing in type

        if (type == 1) { // if type is 1, Temp
            token = strtok(NULL, ","); // gettting token from line
            double celsius = atof(token);//converting to double and storing in celsius

            processTempData(tempArray, &tempCount, timestamp, type, celsius); //passing to method to store in array

        }else if (type == 2){
            token = strtok(NULL, ","); // gettting token from line
            double kmPerH = atof(token); //converting to double and storing in kmPerH

            token = strtok(NULL, ",");// gettting token from line
            int degrees = atoi(token); //converting to int and storing in degrees

            processWindSDData(windArray, &windCount, timestamp, type, kmPerH, degrees); //passing to method to store in array
          
        }else if (type == 3){
            token = strtok(NULL, ",");// gettting token from line
            double prev = atof(token); //converting to double and storing in prev

            token = strtok(NULL, ","); // gettting token from line
            double current = atof(token);//converting to double and storing in current

            processWindGustData(gustArray, &gustCount, timestamp, type, prev , current); //passing to method to store in array
        }
    }

    //printing each log array
    printTempLog (tempArray, &tempCount);
    printWindSDLog(windArray, &windCount);
    printWindGustLog (gustArray,&gustCount);


    fclose(filePtr); //close file
}