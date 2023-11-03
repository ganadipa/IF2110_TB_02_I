#include <stdio.h>
#include "datetime.h"
#include <time.h>

DATETIME currentDateTime ()
{
    DATETIME D;
    time_t t;

    struct tm* info_time;
    t = time(NULL);
    info_time = localtime(&t);

    Day(D) = info_time->tm_mday;
    Month(D) = info_time->tm_mon + 1; 
    Year(D) = info_time->tm_year + 1900;
    Hour(D) = info_time->tm_hour;
    Minute(D) = info_time->tm_min;
    Second(D) = info_time->tm_sec;
    return D;
}

String DateTimeToString(DATETIME D)
{
    String s;
    createEmptyString(&s, 25);

    addString(&s, intToString(Day(D), 2)); 
    addChar(&s, '/'); 
    addString(&s, intToString(Month(D), 2));
    addChar(&s, '/');
    addString(&s, intToString(Year(D), 4));
    addChar(&s, ' ');
    addString(&s, intToString(Hour(D), 2));
    addChar(&s, ':');
    addString(&s, intToString(Minute(D), 2));
    addChar(&s, ':');
    addString(&s, intToString(Second(D), 2));
    return(s);
}