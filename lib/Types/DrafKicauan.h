
#ifndef DRAFKICAUAN_H
#define DRAFKICAUAN_H

#include <stdio.h> 
#include "../boolean.h"
#include "../ADT/String/string.h"
#include "Kicauan.h"

#define Nil -1
#define MaxEl 100
/* Nil adalah stack dengan elemen kosong . */

typedef Kicauan infodraf;
typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  infodraf T[MaxEl]; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
} DrafKicau;

//macro stack
#define TopDraf(S) (S).TOP
#define InfoTopDraf(S) (S).T[(S).TOP]

void CreateDraf(DrafKicau *draf);

boolean isDrafEmpty(DrafKicau draf);

void InisialisasiDrafKicau(Kicauan *k, int IDUser); 

void PushDraf(DrafKicau *S, Kicauan k);

void PopDraf(DrafKicau *S, Kicauan *k);

void PrintDraf(DrafKicau S);

#endif

