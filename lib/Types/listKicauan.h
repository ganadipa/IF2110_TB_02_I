/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit, */

#ifndef LISTKICAUAN_H
#define LISTKICAUAN_H

#include "../boolean.h"
#include "./Kicauan.h"
#include "./ListUser.h"


/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */

/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef Kicauan KicauanType; /* type elemen list */
typedef struct
{
    KicauanType *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;           /* >=0, banyaknya elemen efektif */
    int capacity;        /* ukuran list */
} ListKicau ;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListKicau , cara deklarasi dan akses: */
/* Deklarasi : l : ListKicau  */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

/* ********** SELEKTOR ********** */
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListKicau (ListKicau  *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLengthListKicau (ListKicau  l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyListKicau (ListKicau  l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFullListKicau (ListKicau  l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

void printListKicau (ListKicau  l , ListUser user);
/* Proses : Menuliskan isi list dengan traversal */


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListKicau (ListKicau  *l, KicauanType val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListKicau (ListKicau  *l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */


#endif