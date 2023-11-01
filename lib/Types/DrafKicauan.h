
#ifndef _KICAUAN_H
#define _KICAUAN_H

#include "Kicauan.h"
#include <stdio.h> 
#include "../boolean.h"

#define Nil -1
#define MaxEl 100
/* Nil adalah stack dengan elemen kosong . */

typedef Kicauan infotype;
typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  infotype T[MaxEl]; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
} Draf;


void InisialisasiDrafKicau(Kicauan *k, int ID, String user, String teks); 

void SimpanDraf(); 

void TerbitkanDraf(); 




#endif

