/* File: datetime.h */
/* Definisi ADT DATETIME */

#ifndef DATETIME_H
#define DATETIME_H

#include "../../boolean.h"
#include "../String/string.h" 
  

typedef struct{
    int Day;
    int Month;
    int Year;
    int Hour;
    int Minute;
    int Second;
} DATETIME;

#define Day(u) (u).Day
#define Month(u) (u).Month
#define Year(u) (u).Year
#define Hour(u) (u).Hour
#define Minute(u) (u).Minute
#define Second(u) (u).Second

DATETIME currentDateTime ();
/* I.S. Mendapatkan Time Local */
/* F.S. Terbentuk Time Local */

String DateTimeToString(DATETIME D);

#endif