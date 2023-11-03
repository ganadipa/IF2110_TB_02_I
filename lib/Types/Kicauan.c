#include <stdio.h>
#include "Kicauan.h"

/* ********** KONSTRUKTOR ********** */
void InisialisasiKicau(Kicauan *k,int IDuser){
    userKicau(*k) = IDuser;
    likeKicau(*k) = 0;
    isUtas(*k) = false;
    LinkUtas(*k) = NULL;
    lenUtas(*k) = 0;
}
/**
 * I.S. u sembarang
 * F.S. user memiliki name "user" dan ID "ID", dan properti sisanya default.
*/

void  nambahlenUtas(Kicauan *k){
    lenUtas(*k)++;
}

void  kuranglenUtas(Kicauan *k){
    lenUtas(*k)--;
}

void setIsUtasTrue ( Kicauan *k){
    isUtas(*k) = true;
}

void setKicauID (Kicauan *k, int IDKicau){
    IDKicau(*k) = IDKicau;
}

void setKicauDateTime(Kicauan *k){
    DATETIME D;
    D = currentDateTime ();
    dateTimeKicau(*k) = DateTimeToString(D);
}
/**
 * I.S. k sudah diinisilisasi
 * F.S. Mengeset dateTime menjadi datetime sekarang
*/
void setText(Kicauan *k, String teks){
    teksKicau(*k) = teks;
}
/**
 * I.S. k sudah diinisilisasi
 * F.S. Mengeset text menjadi text terbaru
*/

void addLike(Kicauan *k){
    likeKicau(*k) = likeKicau(*k) + 1;
}
/**
 * I.S. k sudah diinisilisasi
 * F.S. Mengincrement like 
*/


void printKicauan(Kicauan k, String nama ){
    printf("\n");
    printf(" Detail Kicauan :");
    printf("\n| ID = %d", IDKicau(k));
    printf("\n| ID = %d", userKicau(k));
    printf("\n| ");
    displayString( nama);
    printf("\n| ");
    displayString(dateTimeKicau(k));
    printf("\n| ");
    displayString(teksKicau(k));
    printf("\n| Disukai : %d\n", likeKicau(k));
    printf("\n");
}

 