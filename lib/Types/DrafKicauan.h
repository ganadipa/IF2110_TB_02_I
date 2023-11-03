
#ifndef _KICAUAN_H
#define _KICAUAN_H

#include "Kicauan.h"
#include <stdio.h> 
#include "../boolean.h"

#define Nil -1
#define MaxEl 100
/* Nil adalah stack dengan elemen kosong . */

typedef Kicauan infodraf;
typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  Kicauan T[MaxEl]; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
} DrafKicau;

#define TopDraf(S) (S).TOP
#define InfoTopDraf(S) (S).T[(S).TOP]

void CreateDraf(DrafKicau *draf);

boolean isDrafEmpty(DrafKicau draf);

void InisialisasiDrafKicau(Kicauan *k, int IDUser); 

void PushDraf(DrafKicau *S, Kicauan k);

void PopDraf(DrafKicau *S, Kicauan *k);

#endif

