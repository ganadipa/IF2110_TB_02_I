#include <stdio.h>
#include "datetime.h"
#include <time.h>

void CreateDateTime(DATETIME *D){
    D->Day = 00;
    D->Month = 0;
    D->Year = 0;
    D->Hour = 0;
    D->Minute = 0;
    D->Second = 0;
}
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

DATETIME StringToDateTime(String datetime)
{
    DATETIME D;
    CreateDateTime(&D);
    int i;
    int ctr=0;
    for(i=0;i<datetime.maxLength;i++){
        if (datetime.buffer[i] != ' ' && datetime.buffer[i] != '/' && datetime.buffer[i] != ':' ){
            if (ctr < 2 ){
            D.Day = D.Day*10 + datetime.buffer[i] - '0';
            ctr++;
            }
            else if (ctr < 4) {
                D.Month = D.Month*10 + datetime.buffer[i] - '0';
                ctr++;
            } else if (ctr < 8){
                D.Year = D.Year*10 + datetime.buffer[i] - '0';
                ctr++;
            } else if (ctr < 10){
                D.Hour = D.Hour*10 + datetime.buffer[i] -'0';
                ctr++;
            } else if (ctr < 12){
                D.Minute = D.Minute*10 + datetime.buffer[i] - '0';
                ctr++;
            } else if (ctr < 14){
                D.Second = D.Second*10 + datetime.buffer[i] - '0';
                ctr++;
            }
        }
        
    }
    return D;
}

