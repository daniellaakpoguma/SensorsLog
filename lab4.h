#ifndef LAB4_H
#define LAB4_H
#include <time.h>

//Structs
    struct Temp{
        time_t Timestamp;
        int Type;
        double Celsius;
    };

    struct WindSpeedAndDirection{
        time_t Timestamp;
        int Type;
        double KmPerH;
        int Degrees;
    };

    struct WindGust{
        time_t Timestamp;
        int Type;
        double Prev;
        double Current;
    };

//Temp Fucntions
void processTempData(struct Temp tempArray[], int* tempCount, time_t timestamp, int type, double celsius);
void printTempLog (struct Temp tempArray[],int* tempCount);

//Wind Speed Direction Functins
void processWindSDData(struct WindSpeedAndDirection windArray[], int* windCount, time_t timestamp, int type, int kmPerH,double degrees);
void printWindSDLog (struct WindSpeedAndDirection windArray[],int* windCount);

//Wind Gust Fucntions
void checkWindGustTrend(double prev, double current, char* status);
void processWindGustData(struct WindGust gustArray[], int* gustCount, time_t timestamp, int type, double prev ,double current );
void printWindGustLog (struct WindGust gustArray[],int* gustCount);

#endif 