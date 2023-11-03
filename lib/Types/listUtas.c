#include <stdio.h>
#include "listUtas.h"
#include <stdlib.h>


AddressUtas newNodeUtas(String teks, int IDuser, int indexUtas, String nama, String waktu) {
    AddressUtas ptr = (AddressUtas) malloc(sizeof(NodeUtas));
    if (ptr != NULL) {
        IDUSERDIUTAS(ptr) = IDuser;
        NAMADIUTAS(ptr) = nama;
        DATETIMEUTAS(ptr) = waktu;
        TEKSDIUTAS(ptr) = teks;
        NEXT_Linked(ptr) = NULL;
        INDEXUTAS(ptr) = indexUtas;
    }
    return ptr;
}

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */
