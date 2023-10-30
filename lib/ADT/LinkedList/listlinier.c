#include <stdio.h>
#include <stdlib.h>
#include "./listlinier.h"

/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah integer */

Address newNode_ListLinier(ElType val) {
    Address ptr = (Address) malloc(sizeof(Node));
    if (ptr != NULL) {
        INFO_ListLinier(ptr) = val;
        NEXT_ListLinier(ptr) = NULL;
    }
    return ptr;
}

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

typedef Address List;

#define IDX_UNDEF_ListLinier (-1)
#define FIRST_ListLinier(l) (l)
/**
 * List == Address == node()
*/

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListLinier(List *l)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    FIRST_ListLinier(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty_ListLinier(List l) 
/* Mengirim true jika list kosong */
{
    return FIRST_ListLinier(l) == NULL;
}

/****************** GETTER SETTER ******************/
ElType getElmt_ListLinier(List l, int idx)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
{
    Address p = FIRST_ListLinier(l);
    int i = 0;
    while (i < idx) {
        p = NEXT_ListLinier(p);
        i++;
    }
    return INFO_ListLinier(p);
}

void setElmt_ListLinier(List *l, int idx, ElType val)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
{
    Address ptr = FIRST_ListLinier(*l);
    int i =0;
    while (i < idx) {
        ptr = NEXT_ListLinier(ptr);
        i++;
    }

    INFO_ListLinier(ptr) = val;
}

int indexOf_ListLinier(List l, ElType val)
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
{
    int i = 0;
    Address p = FIRST_ListLinier(l);
    while (p!= NULL) {
        if (INFO_ListLinier(p) == val) return i;
        p = NEXT_ListLinier(p);
        i++;
    }

    return IDX_UNDEF_ListLinier;


}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/

void insertFirst_ListLinier(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
{
    insertAt_ListLinier(l, val, 0);
}

void insertLast_ListLinier(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    insertAt_ListLinier(l, val, length_ListLinier(*l));
}

void insertAt_ListLinier(List *l, ElType val, int idx)
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    if (isEmpty_ListLinier(*l)) {
        Address nn = newNode_ListLinier(val);
        FIRST_ListLinier(*l) = nn;
        return;
    } 

    Address nn = newNode_ListLinier(val);
    Address ptr = FIRST_ListLinier(*l);

    if (idx == 0) {
        NEXT_ListLinier(nn) = ptr;
        FIRST_ListLinier(*l) = nn;
        return;
    }

    int i = 0;
    while (i < idx-1)
    {
        ptr = NEXT_ListLinier(ptr);
        ++i;
    }

    NEXT_ListLinier(nn) = NEXT_ListLinier(ptr);
    NEXT_ListLinier(ptr) = nn;
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst_ListLinier(List *l, ElType *val)
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
{
    deleteAt_ListLinier(l, 0, val);
}
void deleteLast_ListLinier(List *l, ElType *val)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
{
    deleteAt_ListLinier(l, length_ListLinier(*l)-1, val);
}

void deleteAt_ListLinier(List *l, int idx, ElType *val)
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
{
    Address ptr = FIRST_ListLinier(*l);
    if (idx == 0) {
        *val = INFO_ListLinier(ptr);
        FIRST_ListLinier(*l) = NEXT_ListLinier(ptr);
        NEXT_ListLinier(ptr) = NULL;
    } else {
        int i = 0;
        while (i < idx-1) {
            ptr = NEXT_ListLinier(ptr);
            i++;
        }
        
        Address tmp = NEXT_ListLinier(ptr);
        *val = INFO_ListLinier(NEXT_ListLinier(ptr));
        NEXT_ListLinier(ptr) = NEXT_ListLinier(NEXT_ListLinier(ptr));
        free(tmp);
    }
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList_ListLinier(List l)
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    if (isEmpty_ListLinier(l)) {
        printf("[]");
        return;
    } else {
        printf("[");
        Address ptr = FIRST_ListLinier(l);
        while (true)
        {
            printf("%d", INFO_ListLinier(ptr));
            if (NEXT_ListLinier(ptr) == NULL) break;
            ptr = NEXT_ListLinier(ptr);
            printf(",");
        }
        printf("]");
        
    }

    
}

int length_ListLinier(List l) {
    int i = 0;
    Address p = FIRST_ListLinier(l);
    while (p != NULL)
    {
        i++; 
        p = NEXT_ListLinier(p);
    }
    
    return i;
    
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat_ListLinier(List l1, List l2)
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    int length1 = length_ListLinier(l1);
    int length2 = length_ListLinier(l2);
    if (length1 == 0) return l2;
    if (length2 == 0) return l1;

    List l3;
    CreateListLinier(&l3);

    if (length1 == 0 && length2 == 0) return l3;

    // ptr is pointing to l1 and l2;
    Address ptr = FIRST_ListLinier(l1);


    while (true) {
        insertLast_ListLinier(&l3, INFO_ListLinier(ptr));
        if (NEXT_ListLinier(ptr) == NULL) break;
        ptr = NEXT_ListLinier(ptr);
    }

    ptr = FIRST_ListLinier(l2);
    while (true) {
        insertLast_ListLinier(&l3, INFO_ListLinier(ptr));
        if (NEXT_ListLinier(ptr) == NULL) break;
        ptr = NEXT_ListLinier(ptr);
    }

    return l3;
}


