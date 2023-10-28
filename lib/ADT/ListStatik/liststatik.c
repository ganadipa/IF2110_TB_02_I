#include <stdio.h>
#include "./liststatik.h"
/* ********** SELEKTOR ********** */
#define ELMT(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l){
    int i = CAPACITY;
    while (i--) ELMT(*l, i) = MARK;
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l) {
    // get element first non mark
    int i = 0;
    while (ELMT(l, i) == MARK)
    {
        i++;
        if (i == CAPACITY) return 0;
    }
    
    // then get the first MARK
    int j = i;
    while (ELMT(l, j) != MARK) 
    {
        j ++;
        if (j == CAPACITY) break;
    }
    return j-i;


}
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l) {
    int i = 0;
    while (ELMT(l, i) == MARK)
    {
        i++;
        if (i == CAPACITY) return 0;
    }

    return i;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListStatik l){
    // get element first non mark
    int i = 0;
    while (ELMT(l, i) == MARK)
    {
        i++;
        if (i == CAPACITY) return 0;
    }
    
    // then get the first MARK
    int j = i;
    while (ELMT(l,j) != MARK) 
    {
        j ++ ;
        if (j == CAPACITY) break;
    }

    return j-1;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i) {
    return ( 0 <= i && i< CAPACITY );
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListStatik l, IdxType i) {
    return (getFirstIdx(l)<= i && i<= getFirstIdx(l)+ listLength(l)-1);
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l) {
    return (listLength(l) == 0);
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFull(ListStatik l) {
return (listLength(l) == CAPACITY);}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l) {
    CreateListStatik(l);
    int n;
    int i;

    while (true)
    {
        scanf("%i", &n);
        if (0<= n && n<= CAPACITY) break;
    }

    for (int i = 0; i < n; i++) scanf("%i", &ELMT(*l, i));
}

/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
void printList(ListStatik l){

    int sz = listLength(l);
    if (sz == 0) {printf("[]");return;}

    int i = getFirstIdx(l);
    printf("[");
    while (sz-- >1)
    {   
        printf("%i,", ELMT(l, i));
        i++;
    }
    printf("%i]", ELMT(l,i));
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
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus) {
    int i = getFirstIdx(l1);
    int j = getFirstIdx(l2);
    int k = 0;

    int length = listLength(l1);
    ListStatik res;
    CreateListStatik(&res);
    for (k = 0; k < length; k++) ELMT(res, k) = ELMT(l1, k) - ELMT(l2, k) + 2*(plus)*(ELMT(l2, k));

    return res;

}
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2) {
    if (listLength(l1) != listLength(l2)) return false;

    int i = 0;
    for (i = 0; i < CAPACITY; i++) 
    {
        if (ELMT(l1, i) != ELMT(l2, i)) return false;
    }

    return true;


}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val) {
    int length = listLength(l);
    int fi = getFirstIdx(l);
    int i;
    for (i = fi; i<fi+length; i++)
    {
        if (ELMT(l,i) == val) return i;
    }

    return IDX_UNDEF;

}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min){
    int bestMax = ELMT(l, getFirstIdx(l));
    int bestMin = ELMT(l, getFirstIdx(l));

    int length = listLength(l);
    int i1 = getFirstIdx(l);
    int i;
    for ( i = i1; i < i1 + length; i++ )
    {
        if (bestMax < ELMT(l, i)) bestMax = ELMT(l, i);
        if (bestMin > ELMT(l, i)) bestMin = ELMT(l, i);
    }

    *max = bestMax;
    *min = bestMin;

}
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val){
    int length = listLength(*l);
    int i1 = getFirstIdx(*l);

    while (length--)
    {
        ELMT(*l, i1 + length + 1) = ELMT(*l, i1 + length + 0);
    }
    ELMT(*l, i1) = val;
}
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
void insertAt(ListStatik *l, ElType val, IdxType idx){
    int length = listLength(*l);
    int ilast = getLastIdx(*l);
    int i;
    for ( i = 0; i < length; i++)
    {
        if (ilast -i +1 == idx) break;
        ELMT(*l, ilast-i+1)  = ELMT(*l, ilast-i);
    }
    ELMT(*l, ilast-i+1) = val;
}
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListStatik *l, ElType val){
    ELMT(*l, getFirstIdx(*l) + listLength(*l)) = val;
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */

void deleteAt(ListStatik *l, ElType *val, IdxType idx) {
    *val = ELMT(*l, idx);
    while (true)
    {
        if (idx == CAPACITY-1) {ELMT(*l, idx) = MARK; break;}
        if (ELMT(*l, idx) == MARK) break;
        ELMT(*l, idx) = ELMT(*l, idx+1);
        idx ++;
    }
}
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */

void deleteFirst(ListStatik *l, ElType *val) {
    deleteAt(l, val, getFirstIdx(*l));
}
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */

void deleteLast(ListStatik *l, ElType *val){
    deleteAt(l, val, getLastIdx(*l));
}
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc){
    int p1 = getFirstIdx(*l);
    int p2 = getLastIdx(*l);
    while (p1 < p2)
    {
        int best = ELMT(*l, p1);
        int tmp_i = p1;
        int i;
        for (i = p1; i<=p2; i++)
        {

            if (ELMT(*l, i) == best) continue;
            if (ELMT(*l, i) < best && asc)
            {
                best = ELMT(*l, i);
                tmp_i = i;
            }
            if (ELMT(*l, i) > best && !asc)
            {
                best = ELMT(*l, i);
                tmp_i = i;
            }
        }
        int _;
        
        deleteAt(l, &_, tmp_i);
        insertAt(l, best, p1);

        p1++;
    }
   
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */