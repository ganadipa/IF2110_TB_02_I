#include <stdio.h>
#include <stdlib.h>
#include "listKicauan.h"
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListKicau(ListKicau *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    BUFFER(*l) = (KicauanType*)malloc((capacity) * sizeof(KicauanType));
    NEFF(*l) = 0;
    CAPACITY (*l) = capacity;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLengthListKicau(ListKicau l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
    return NEFF(l);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyListKicau(ListKicau l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{
    return NEFF(l) == 0;
}

boolean isFullListKicau(ListKicau l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
    return NEFF(l) == CAPACITY(l);
}


// PRINT LINST KICAU INI MASIH SEMENTARA
void printListKicau(ListKicau l)
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
{
    int i;
    if (isEmptyListKicau(l))
    {
        printf("List Kicauan Kosong");
    } else 
    {
        for (i = 0; i < NEFF(l); i++)
        {
            printKicauan(ELMT(l, i));
        }
    }
}


/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListKicau(ListKicau *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    CAPACITY(*l) = CAPACITY(*l) + num;
    BUFFER(*l) = realloc(BUFFER(*l), (CAPACITY(*l)) * sizeof(KicauanType));

}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListKicau(ListKicau *l, KicauanType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    if (!isFullListKicau(*l))
    {
        ELMT(*l, NEFF(*l)) = val;
        NEFF(*l) = NEFF(*l) + 1;
    }else {
        expandListKicau(l, 200);
        ELMT(*l, NEFF(*l)) = val;
        NEFF(*l) = NEFF(*l) + 1;
    }
}