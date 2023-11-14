#include <stdio.h>
#include <stdlib.h>
#include "Kicauan.h"

/* ********** KONSTRUKTOR ********** */
void InisialisasiKicau(Kicauan *k,int IDuser){
    userKicau(*k) = IDuser;
    likeKicau(*k) = 0;
    createReplyTree(&BALASAN(*k), 100);
    IDUTAS(*k) = 0; //klo idUtas 0 maka tidak ada Utas
    FIRST(*k) = NULL;
    LEN_ANAKUTAS(*k) = 0;
}
/**
 * I.S. u sembarang
 * F.S. user memiliki name "user" dan ID "ID", dan properti sisanya default.
*/

void  nambahlenUtas(Kicauan *k){
    LEN_ANAKUTAS(*k)++;
}

void  kuranglenUtas(Kicauan *k){
    LEN_ANAKUTAS(*k)--;
}

void insertAtAnakUtas(Kicauan *k, int indeksUtas, String teks, String namaUser, String time){
    AddressUtas temp = FIRST(*k);
    AddressUtas p = newNodeUtas(teks, namaUser, time);
    while(indeksUtas > 2){
        temp = NEXT_Linked(temp);
        indeksUtas--;
    }
    if (NEXT_Linked(temp) != NULL){
        NEXT_Linked(p) = NEXT_Linked(temp);
        NEXT_Linked(temp) = p;
    } else {
        NEXT_Linked(p) = NEXT_Linked(temp);
        NEXT_Linked(temp) = NULL;
    }
    LEN_ANAKUTAS(*k) ++;
}

void deleteAtAnakUtas(Kicauan *k ,int indeksUtas, String *teks, String *namaUser, String *time){
    AddressUtas temp = FIRST(*k);
    
    if (indeksUtas == 1){
        AddressUtas test = temp;
        temp = NULL;
        *teks = TEKSDIUTAS(test);
        *namaUser = NAMADIUTAS(test);
        *time = DATETIMEUTAS(test);
        NEXT_Linked(test) = NULL;
        FIRST(*k) = NULL;
        free(test);

    } else if (indeksUtas > 1){
        while(indeksUtas > 2){
            temp = NEXT_Linked(temp);
            indeksUtas--;
        }
        if(NEXT_Linked(NEXT_Linked(temp)) != NULL){
            AddressUtas test = NEXT_Linked(temp);
            NEXT_Linked(temp) = NEXT_Linked(NEXT_Linked(temp));
            *teks = TEKSDIUTAS(test);
            *namaUser = NAMADIUTAS(test);
            *time = DATETIMEUTAS(test);
            NEXT_Linked(test) = NULL;
            free(test);
        } else {
            AddressUtas test = NEXT_Linked(temp);
            NEXT_Linked(temp) = NULL;
            *teks = TEKSDIUTAS(test);
            *namaUser = NAMADIUTAS(test);
            *time = DATETIMEUTAS(test);
            NEXT_Linked(test) = NULL;
            free(test);
        }
    }
    LEN_ANAKUTAS(*k) --;
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
    printf("\n| ");
    displayString(nama);
    printf("\n| ");
    displayString(dateTimeKicau(k));
    printf("\n| ");
    displayString(teksKicau(k));
    printf("\n| Disukai : %d\n", likeKicau(k));
    printf("\n");
}

 