#ifndef KICAUAN_H
#define KICAUAN_H
#include "../boolean.h"
#include "./User.h"
#include "../ADT/String/string.h" 
#include "../ADT/DateTime/datetime.h"  


typedef struct {
    int IDKicau;
    int  IDuser;
    String dateTime;
    String text;
    int like;
} Kicauan;

#define IDKicau(u) (u).IDKicau
#define userKicau(u) (u).IDuser
#define dateTimeKicau(u) (u).dateTime
#define teksKicau(u) (u).text
#define likeKicau(u) (u).like

void InisialisasiKicau(Kicauan *k, int IDuser);
/**
 * I.S. u sembarang
 * F.S. user memiliki name "user" dan ID "ID", dan properti sisanya default.
*/

void setKicauID(Kicauan *k, int ID);
/**
 * I.S. k sudah diinisilisasi
 * F.S. Mengeset id menjadi id sekarang
*/

void setKicauDateTime(Kicauan *k);
/**
 * I.S. k sudah diinisilisasi
 * F.S. Mengeset dateTime menjadi datetime sekarang
*/
void setText(Kicauan *k, String teks);
/**
 * I.S. k sudah diinisilisasi
 * F.S. Mengeset text menjadi text terbaru
*/

void addLike(Kicauan *k);
/**
 * I.S. k sudah diinisilisasi
 * F.S. Mengincrement like 
*/

void printKicauan(Kicauan k, String nama);
/**
 * Print Kicauan 
*/



#endif