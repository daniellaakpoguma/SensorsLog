#ifndef TEMP_H
#define TEMP_H
#include "lab4.h"

//Structs
struct Temp{
    time_t Timestamp;
    int Type;
    double Celsius;
};

//Temp Fucntions
void processTempData(struct Temp tempArray[], int* tempCount, time_t timestamp, int type, double celsius);
void printTempLog (struct Temp tempArray[],int* tempCount);

#endif 