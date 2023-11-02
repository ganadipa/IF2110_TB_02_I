#include <stdio.h>
#include "../Kicauan.h"

/* ********** KONSTRUKTOR ********** */
void InisialisasiKicau(Kicauan *k,int IDuser){
    userKicau(*k) = IDuser;
    likeKicau(*k) = 0;
}
/**
 * I.S. u sembarang
 * F.S. user memiliki name "user" dan ID "ID", dan properti sisanya default.
*/

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
    printf(" Detail Kicauan :");
    printf("\n| ID = %d", IDKicau(k));
    printf("\n| ");
//  ELMT_LISTUSER(LISTUSER(*app), IDUSER).name
    displayString( nama);
    printf("\n| ");
    displayString(dateTimeKicau(k));
    printf("\n| ");
    displayString(teksKicau(k));
    printf("\n| Disukai : %d\n", likeKicau(k));
}

 