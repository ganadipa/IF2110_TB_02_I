    /* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */
#include <stdio.h>
#include "liststatik.h"
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l){
    int i;
    for (i = IDX_MIN; i < CAPACITY;i++){
        ELMT(*l , i) = MARK;
    }
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listStatikLength(ListStatik l){
    int i=IDX_MIN;
    while ((ELMT(l,i)!=MARK) && i<CAPACITY){
        i++;
    }
    return i;
}
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  

/* *** Selektor INDEKS *** */
IdxType getFirstIdxStatik(ListStatik l){
    return IDX_MIN;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdxStatik(ListStatik l){
    return listStatikLength(l)-1;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidStatik(ListStatik l, IdxType i){
    return (i >= IDX_MIN && i < CAPACITY);
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEffStatik(ListStatik l, IdxType i){
    return (i>=IDX_MIN && i<listStatikLength(l));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyStatik(ListStatik l){
    return (listStatikLength(l) == 0);
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFullStatik(ListStatik l){
    return (listStatikLength(l) == CAPACITY);
}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readListStatik(ListStatik *l){
    int n, i;
    scanf("%d", &n);
    while (!(n>=0 && n<= CAPACITY)){
        scanf("%d", &n);
    }
    if (n==0){
        CreateListStatik(l);
    }
    else{
        CreateListStatik(l);
        for (i = 0; i < n;i++){
            scanf("%d",&ELMT(*l,i));
        }
    }
}
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
void printListStatik(ListStatik l){
    if (isEmptyStatik(l)){
        printf("[]");
    }
    else{
        int i;
        printf("[");
        for (i = IDX_MIN; i <= getLastIdxStatik(l);i++){
            if (i!=IDX_MIN){
                printf(",");
            }
            printf("%d", ELMT(l, i));
            
        }
        printf("]");
    }
}
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusListStatik(ListStatik l1, ListStatik l2, boolean plus){
    int i;
    if (plus){
        for (i = IDX_MIN; i < listStatikLength(l1);i++){
            ELMT(l1, i) += ELMT(l2, i);
        }
    }
    else{
        for (i = IDX_MIN; i < listStatikLength(l1);i++){
            ELMT(l1, i) -= ELMT(l2, i);
        }
    }
    return (l1);
}
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListStatikEqual(ListStatik l1, ListStatik l2){
    if (listStatikLength(l1)!= listStatikLength(l2)){
        return false;
    }
    int i;
    for (i = IDX_MIN; i < listStatikLength(l1);i++){
        if (ELMT(l1,i)!=ELMT(l2,i)){
            return false;
        }
    }
    return true;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOfListStatik(ListStatik l, ElType val){
    int i = IDX_MIN;
    for (i; i < listStatikLength(l); i++){
        if (ELMT(l,i)==val){
            return i;
        }
    }
    return IDX_UNDEF;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValuesStatik(ListStatik l, ElType *max, ElType *min){
    int terbesar, terkecil;
    int i = IDX_MIN;
    terbesar = ELMT(l,0);
    terkecil = ELMT(l,0);
    for (i; i < listStatikLength(l);i++){
        if (ELMT(l,i)>terbesar){
            terbesar = ELMT(l, i);
        }
        if (ELMT(l,i)<terkecil){
            terkecil = ELMT(l, i);
        }
    }
    *max = terbesar;
    *min = terkecil;
}
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirstStatik(ListStatik *l, ElType val){
    int i = listStatikLength(*l) - 1;
    for (i; i >= IDX_MIN;i--){
        ELMT(*l, i + 1) = ELMT(*l, i);
    }
    ELMT(*l, 0) = val;
}
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
void insertAtStatik(ListStatik *l, ElType val, IdxType idx){
    int i = listStatikLength(*l) - 1;
    for (i; i >= idx;i--){
        ELMT(*l, i + 1) = ELMT(*l, i);
    }
    ELMT(*l, idx) = val;
}

/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
void insertLastStatik(ListStatik *l, ElType val){
    ELMT(*l, listStatikLength(*l)) = val;
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirstStatik(ListStatik *l, ElType *val){
    *val = ELMT(*l, IDX_MIN);
    int i = IDX_MIN;
    for (i; i < getLastIdxStatik(*l);i++){
        ELMT(*l, i) = ELMT(*l, i + 1);
    }
    ELMT(*l, getLastIdxStatik(*l)) = MARK;
}
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
void deleteAtStatik(ListStatik *l, ElType *val, IdxType idx){
    *val = ELMT(*l, idx);
    int i = idx;
    for (i; i < getLastIdxStatik(*l);i++){
        ELMT(*l, i) = ELMT(*l, i + 1);
    }
    ELMT(*l, getLastIdxStatik(*l)) = MARK;
}
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
void deleteLastStatik(ListStatik *l, ElType *val){
    deleteAtStatik(l, val, getLastIdxStatik(*l));
}
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********** SORTING ********** */
void sortListStatik(ListStatik *l, boolean asc) {
    int i, temp;
    i = IDX_MIN;
    if (!isEmptyStatik(*l)) {
        while (i != getLastIdxStatik(*l)) {
            if ((asc && (ELMT(*l, i) > ELMT(*l, i + 1))) || (!asc && (ELMT(*l, i) < ELMT(*l, i + 1)))) {
                temp = ELMT(*l, i + 1);
                ELMT(*l, i + 1) = ELMT(*l, i);
                ELMT(*l, i) = temp;
                i = IDX_MIN;
            }else{
                i += 1;
        }
    }
}}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */


