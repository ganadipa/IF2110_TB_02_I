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
    String namaUser;    // Nama dari user yang melakukan utas 
    String dateTime;    // dateTime Utas
    String teks;        // teks dari utas
    AddressUtas next;   // link untuk ke next dari linked list
} NodeUtas;
typedef AddressUtas listutas;


#define NEXT_Linked(p) (p)->next
#define NAMADIUTAS(p) (p)->namaUser
#define TEKSDIUTAS(p) (p)->teks
#define DATETIMEUTAS(p) (p)->dateTime

AddressUtas newNodeUtas(String teks, String nama, String waktu);

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */



#endif