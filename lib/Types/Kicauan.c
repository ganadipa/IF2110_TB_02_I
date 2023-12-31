#include <stdio.h>
#include <stdlib.h>
#include "Kicauan.h"


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

void insertAtAnakUtas(Kicauan *k, int indeksUtas, String teks, String namaUser, String time)
// Menambah utas sesuai dengan indeks utas
{
    AddressUtas temp = FIRST(*k);
    AddressUtas p = newNodeUtas(teks, namaUser, time);
    if (indeksUtas == 1){
        NEXT_Linked(p) = temp;
        FIRST(*k) = p;
        LEN_ANAKUTAS(*k) ++;
        return;
    }
    while(indeksUtas > 2){
        temp = NEXT_Linked(temp);
        indeksUtas--;
    }
    if (NEXT_Linked(temp) != NULL){
        NEXT_Linked(p) = NEXT_Linked(temp);
        NEXT_Linked(temp) = p;
    } else {
        NEXT_Linked(p) = NEXT_Linked(temp);
        NEXT_Linked(temp) = p;
    }
    LEN_ANAKUTAS(*k) ++;
}

void deleteAtAnakUtas(Kicauan *k ,int indeksUtas, String *teks, String *namaUser, String *time)
// Menghapus utas sesuai dengan indeks utas
{
    AddressUtas temp = FIRST(*k);
    
    if (indeksUtas == 1){
        FIRST(*k) = NEXT_Linked(temp);
        *teks = TEKSDIUTAS(temp);
        *namaUser = NAMADIUTAS(temp);
        *time = DATETIMEUTAS(temp);
        NEXT_Linked(temp) = NULL;
        temp = NULL;
        
        free(temp);

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

 
unsigned long long int hashFunction(String tagar){
    unsigned long long int hash = 0;
    for (int i = 0; i < stringLength(tagar); i++) {
        hash = (hash + tagar.buffer[i])*97 % TABLE_SIZE;
    }
    return hash;
}

void inisialisasiHashTable(HashTable *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        createEmptyString(&(*table)[i].tagar, 280);
        (*table)[i].kicauan = NULL;
        (*table)[i].isOccupied = 0;
    }
}

void insertKicauankeTable(HashTable *table, String tagar, Kicauan *kicauan) {
    unsigned long long int index = hashFunction(tagar);
    // printf("%d\n", index);
    while ((*table)[index].isOccupied) {
        if (isStringInsensitivelyEqual((*table)[index].tagar, tagar)) {
            printf("Tagar ini milik kicauan lain\n");
            return;
        }
        index = (index + 1) % TABLE_SIZE; // Linear probing
    }
    (*table)[index].tagar = tagar; // Sesuaikan ini jika perlu melakukan duplikasi string
    (*table)[index].kicauan = kicauan;
    (*table)[index].isOccupied = 1;
    // displayString((*table)[index].tagar);
    // String name = {"GANA", 20};
    // printKicauan(*(*table)[index].kicauan, name);
    // printf("  Tagar MASUK");
}


