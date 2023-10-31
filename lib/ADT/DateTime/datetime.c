#include <stdio.h>
#include <stdlib.h>
#include "datetime.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
int GetMaxDay(int M, int Y)
/* Mengirimkan jumlah hari maksimum pada bulan M dan tahun Y */
/* Prekondisi: 1 <= M <= 12*/
/* Hint: Perhatikan Leap Year. Leap Year adalah tahun dengan 29 hari pada bulan Februari */
/* Aturan Leap Year: */
/* 1. Jika angka tahun itu habis dibagi 400, maka tahun itu sudah pasti tahun kabisat. 8*/
/* 2. Jika angka tahun itu tidak habis dibagi 400 tetapi habis dibagi 100, maka tahun itu sudah pasti bukan merupakan tahun kabisat. */
/* 3. Jika angka tahun itu tidak habis dibagi 400, tidak habis dibagi 100 akan tetapi habis dibagi 4, maka tahun itu merupakan tahun kabisat. */
/* 4. Jika angka tahun tidak habis dibagi 400, tidak habis dibagi 100, dan tidak habis dibagi 4, maka tahun tersebut bukan merupakan tahun kabisat. */
{
    if ((M == 1) || (M == 3) || (M == 5) || (M == 7) || (M == 8) || (M == 10) || (M == 12))
    {
        return 31;
    } else if ((M == 4) || (M == 6) || (M == 9) || (M == 11)) 
    {
        return 30;
    } else if (M == 2)
    {
        if ((Y % 400 == 0) || ((Y % 100 != 0) && (Y % 4 == 0)))
        {
            return 29;
        }
    }

    return 28;
}

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s)
/* Mengirim true jika D,M,Y,h,m,s dapat membentuk D yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah DATETIME */
{
    return ((h >= 0 && h <= 23) && (m >= 0 && m <= 59) && (s >= 0 && s <= 59) && (M <= 12 && M >= 1) && (D >=1 && D <= GetMaxDay(M, Y)));
}

/* *** Konstruktor: Membentuk sebuah DATETIME dari komponen-komponennya *** */
void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss)
/* Membentuk sebuah DATETIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, MM, YYYY, h, m, s valid untuk membentuk DATETIME */
{
    Day (*D) = DD;
    Month (*D) = MM;
    Year (*D) = YYYY;
    CreateTime (&Time(*D), hh, mm, ss);
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaDATETIME(DATETIME *D)
/* I.S. : D tidak terdefinisi */
/* F.S. : D terdefinisi dan merupakan DATETIME yang valid */
/* Proses : mengulangi membaca komponen DD, MM, YY, h, m, s sehingga membentuk D */
/* yang valid. Tidak mungkin menghasilkan D yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen DD, MM, YY, h, m, s
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika DATETIME tidak valid maka diberikan pesan: "DATETIME tidak valid", dan pembacaan
    diulangi hingga didapatkan DATETIME yang valid. */
/* Contoh:
    32 13 2023 12 34 56
    DATETIME tidak valid
    31 12 2023 12 34 56
    --> akan terbentuk DATETIME <31,12,2023,12,34,56> */
{
    int DD, MM, YY, h, m, s;
    do 
    {
        scanf("%d %d %d %d %d %d", &DD, &MM, &YY, &h, &m, &s);
        if (!IsDATETIMEValid(DD, MM, YY, h, m, s))
        {
            printf("DATETIME tidak valid\n");
        }
    } while (!IsDATETIMEValid(DD, MM, YY, h, m, s));
    CreateDATETIME(D, DD, MM, YY, h, m, s);
}

void TulisDATETIME(DATETIME D)
/* I.S. : D sembarang */
/* F.S. : Nilai D ditulis dg format DD/MM/YYYY HH:MM:SS */
/* Proses : menulis nilai setiap komponen D ke layar dalam format DD/MM/YYYY HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
{
    printf("%d/%d/%d ", Day(D), Month(D), Year(D));
    TulisTIME(Time(D));
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok operasi relasional terhadap DATETIME *** */
boolean DEQ(DATETIME D1, DATETIME D2)
/* Mengirimkan true jika D1=D2, false jika tidak */
{
    return ((Day(D1) == Day(D2)) && (Month(D1) == Month(D2)) && (Year(D1) == Year(D2)) && (Hour(Time(D1))) == (Hour(Time(D2))) && (Minute(Time(D1))) == (Minute(Time(D2))) && (Second(Time(D1))) == (Second(Time(D2))));
}

boolean DNEQ(DATETIME D1, DATETIME D2)
/* Mengirimkan true jika D1 tidak sama dengan D2 */
{
    return (!DEQ(D1, D2));
}

boolean DLT(DATETIME D1, DATETIME D2)
/* Mengirimkan true jika D1<D2, false jika tidak */
{ 
    if (Year(D1) < Year(D2)) 
    {
        return true;
    } else if (Year(D1) > Year(D2)) 
    {
        return false;
    } else if (Month(D1) < Month(D2)) 
    {
        return true;
    } else if (Month(D1) > Month(D2)) 
    {
        return false;
    } else if (Day(D1) < Day(D2)) 
    {
        return true;
    } else if (Day(D1) > Day(D2)) 
    {
        return false;
    } else if (Hour(Time(D1)) < Hour(Time(D2))) 
    {
        return true;
    } else if (Hour(Time(D1)) > Hour(Time(D2))) 
    {
        return false;
    } else if (Minute(Time(D1)) < Minute(Time(D2))) 
    {
        return true;
    } else if (Minute(Time(D1)) > Minute(Time(D2))) 
    {
        return false;
    } else if (Second(Time(D1)) < Second(Time(D2))) 
    {
        return true;
    } else
    {
        return false;
    }
}

boolean DGT(DATETIME D1, DATETIME D2)
/* Mengirimkan true jika D1>D2, false jika tidak */
{
    return !DLT(D1, D2) && DNEQ(D1, D2);
}

DATETIME DATETIMENextNDetik(DATETIME D, int N)
/* Mengirim salinan D dengan detik ditambah N */
{
    int detikTotal, hariTotal;
    detikTotal =  TIMEToDetik(Time(D)) + N;
    hariTotal = (detikTotal / 86400) + Day(D);

    while (hariTotal > GetMaxDay(Month(D), Year(D)))
    {
        hariTotal -= GetMaxDay(Month(D), Year(D));
        Month(D) += 1;

        if (Month(D) > 12) 
        {
            Month(D) = Month(D) % 12;
            Year(D) += 1;
        }
    }

    Day(D) = hariTotal;
    Time(D) = DetikToTIME(detikTotal % 86400);
    return D;
}

DATETIME DATETIMEPrevNDetik(DATETIME D, int N)
/* Mengirim salinan D dengan detik dikurang N */
{
    int detikTotal, hariTotal;
    detikTotal =  TIMEToDetik(Time(D)) - N;
    
    if (detikTotal < 0)
    {
        hariTotal = detikTotal / 86400 + Day(D) - 1;

        while (hariTotal < 1)
        {
            Month(D) -= 1;
            if (Month(D) < 1) 
            {
                Month(D) = 12;
                Year(D) -= 1;
            }
            hariTotal += GetMaxDay(Month(D), Year(D));
        }
        Day(D) = hariTotal;
        Time(D) = DetikToTIME((detikTotal % 86400) + 86400);
    } else 
    {
        Time(D) = DetikToTIME(detikTotal);
    }

    return D;
}

/* *** Kelompok Operator Aritmetika terhadap DATETIME *** */
long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh)
/* Mengirim DAkh-DAw dlm Detik, dengan kalkulasi */
/* Prekondisi: DAkh > DAw */
{
    long int durasi = 0;
    long int hariMax;

    long int hariAw = Day(DAw);
    long int bulanAw = Month(DAw);
    long int tahunAw = Year(DAw);
    long int jamAw = Hour(Time(DAw));
    long int menitAw = Minute(Time(DAw));
    long int detikAw = Second(Time(DAw));

    long int hariAkh = Day(DAkh);
    long int bulanAkh = Month(DAkh);
    long int tahunAkh = Year(DAkh);
    long int jamAkh = Hour(Time(DAkh));
    long int menitAkh = Minute(Time(DAkh));
    long int detikAkh = Second(Time(DAkh));

    while (tahunAw < tahunAkh || bulanAw < bulanAkh || hariAw < hariAkh || jamAw < jamAkh || menitAw < menitAkh || detikAw < detikAkh) 
    {
        hariMax = GetMaxDay(bulanAw, tahunAw);
        durasi ++;
        detikAw ++;

        if (detikAw == 60) 
        {
            detikAw = 0;
            menitAw++;

            if (menitAw == 60) 
            {
                menitAw = 0;
                jamAw++;

                if (jamAw == 24) 
                {
                    jamAw = 0;
                    hariAw++;

                    if (hariAw > hariMax) 
                    {
                        hariAw = 1;
                        bulanAw++;

                        if (bulanAw > 12) 
                        {
                            bulanAw = 1;
                            tahunAw++;
                        }
                    }
                }
            }
        }
    }
    return durasi;
}