    /* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah integer */

#ifndef LISTUTAS_H
#define LISTUTAS_H

#include "../boolean.h"
#include "../ADT/String/string.h" 
#include "../ADT/DateTime/datetime.h"  

/* Definisi Node : */
typedef struct nodeUtas* AddressUtas;
typedef struct  nodeUtas{
    int indexUtas; //MASUK CONFIG
    int IDUser;
    String namaUser; //MASUK CONFIG
    String dateTime; //MASUK CONFIG
    String teks;    //MASUK CONFIG
    AddressUtas next; 
} NodeUtas;
typedef AddressUtas listutas;


#define NEXT_Linked(p) (p)->next
#define INDEXUTAS(p) (p)->indexUtas
#define IDUSERDIUTAS(p) (p)->IDUser
#define NAMADIUTAS(p) (p)->namaUser
#define TEKSDIUTAS(p) (p)->teks
#define DATETIMEUTAS(p) (p)->dateTime

AddressUtas newNodeUtas(String teks, int IDuser, int indexUtas, String nama, String waktu);

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */



#endif