#include <stdio.h>
#include "./ListUser.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListUser(ListUser *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Set length = 0 */
{
    LENGTH_LISTUSER(*l) = 0;
}



/* ********** Test Indeks yang valid ********** */
boolean isIdxValid_ListUser(ListUser l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return 0 <= i && i <= CAPACITY_ListUser;

}
boolean isIdxEff_ListUser(ListUser l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
{
    return 0 <= i && i<= LENGTH_LISTUSER(l) -1;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty_ListUser(ListUser l)
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
{
    return LENGTH_LISTUSER(l) == 0;
}
/* *** Test List penuh *** */
boolean isFull_ListUser(ListUser l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
{
    return LENGTH_LISTUSER(l) == CAPACITY_ListUser;
}


/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf_ListUser(ListUser l, User val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
{
    return val.ID;
}


/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst_ListUser(ListUser *l, User val)
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
{
    insertAt_ListUser(l, val, 0);
}
/* *** Menambahkan elemen pada index tertentu *** */
void insertAt_ListUser(ListUser *l, User val, IdxType idx)
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l*/
/* *** Menambahkan elemen terakhir *** */
{
    int i = LENGTH_LISTUSER(*l);
    for (i = LENGTH_LISTUSER(*l); i >= idx + 1; i--) {
        ELMT_LISTUSER(*l, i-1) = ELMT_LISTUSER(*l, i);  
    }

    ELMT_LISTUSER(*l, idx) = val;
    LENGTH_LISTUSER(*l)++;
}
void insertLast_ListUser(ListUser *l, User val)
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    ELMT_LISTUSER(*l, LENGTH_LISTUSER(*l)) = val;
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst_Listuser(ListUser *l, User *val)
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
    deleteAt_ListUser(l, val, 0);
}
/* *** Menghapus elemen pada index tertentu *** */
void deleteAt_ListUser(ListUser *l, User *val, IdxType idx)
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
    *val = ELMT_LISTUSER(*l, idx);
    for (idx = idx; idx < LENGTH_LISTUSER(*l); idx++) {
        ELMT_LISTUSER(*l, idx) = ELMT_LISTUSER(*l, idx+1); 
    }
    LENGTH_LISTUSER(*l)--;
}

/* *** Menghapus elemen terakhir *** */
void deleteLast_ListUser(ListUser *l, User *val)
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
    deleteLast_ListUser(l, val);
}

IdxType searchByName(ListUser l, String name)
/**
 * Mengembalikan true apabila u1 dan u2 memiliki seluruh properti yang sama.
*/
{
    int i = 0;
    int length = LENGTH_LISTUSER(l);
    boolean found = false;
    while (i < length && !found) {
        if (isStringEqual(ELMT_LISTUSER(l,i).name, name)) found = true;
        else {
            i++;
        }
    }

    if (found) return i;
    else return IDX_UNDEF;
}