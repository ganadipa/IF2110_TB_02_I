#include <stdio.h>
#include "datetime.h"
#include <time.h>

int createDatetime ()
{
    struct tm* info_time;
    time_t t;
    t = time(NULL);
    info_time = localtime(&t);
    return (info_time->tm_mday, info_time->tm_mon, info_time->tm_year, info_time->tm_hour, info_time->tm_min, info_time->tm_sec);
}