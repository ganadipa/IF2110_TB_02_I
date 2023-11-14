#ifndef KICAUAN_H
#define KICAUAN_H
#include "../boolean.h"
#include "../ADT/String/string.h" 
#include "../ADT/DateTime/datetime.h"  
#include "ReplyTree.h"
#include "listUtas.h"

typedef struct {
    int IDKicau;
    int IDuser;
    String dateTime;
    String text;
    int like;
    ReplyTree balasan;
    int IDUtas;
    AddressUtas link;
    int lenUtas;
} Kicauan;

#define IDKicau(u) (u).IDKicau
#define userKicau(u) (u).IDuser
#define dateTimeKicau(u) (u).dateTime
#define teksKicau(u) (u).text
#define likeKicau(u) (u).like
#define BALASAN(u) (u).balasan
#define IDUTAS(u) (u).IDUtas
#define FIRST(u) (u).link //ke Utas dengan index pertama 1
#define LEN_ANAKUTAS(u) (u).lenUtas

void InisialisasiKicau(Kicauan *k, int IDuser);
/**
 * I.S. u sembarang
 * F.S. user memiliki name "user" dan ID "ID", dan properti sisanya default.
*/

void  nambahlenUtas(Kicauan *k);

void  kuranglenUtas(Kicauan *k);

void insertAtAnakUtas(Kicauan *k  ,int indeksUtas,String teks,String namaUser, String time);

void deleteAtAnakUtas (Kicauan *k ,int indeksUtas, String *teks, String *namaUser, String *time);



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