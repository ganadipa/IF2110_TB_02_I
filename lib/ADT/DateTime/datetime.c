#include <stdio.h>
#include "datetime.h"
#include <time.h>



DATETIME currentDateTime ()
{
    DATETIME D;
    struct tm* info_time;

    Day(D) = info_time->tm_mday;
    Month(D) = info_time->tm_mon; 
    Year(D) = info_time->tm_year;
    Hour(D) = info_time->tm_hour;
    Minute(D) = info_time->tm_min;
    Second(D) = info_time->tm_sec;
    return D;
}

String DateTimeToString(DATETIME *D)
{
    String s;
    createEmptyString(&s, 25);
    addChar(&s, &D);
    addChar(&s, '/');
    addChar(&s, '/');
    return s;
}

int main(){
    DATETIME tes;
    tes = currentDateTime();
    displayString(DateTimeToString(&tes));
}