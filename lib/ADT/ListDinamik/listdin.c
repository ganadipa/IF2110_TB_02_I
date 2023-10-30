#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    BUFFER(*l) = (int*)malloc((capacity) * sizeof(int));
    NEFF(*l) = 0;
    CAPACITY (*l) = capacity;
}

void dealocateListDin(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    free(BUFFER(*l));
    NEFF(*l) = 0;
    CAPACITY (*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLengthListDin(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
    return NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdxListDin(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
    return IDX_MIN;
}

IdxType getLastIdxListDin(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    return NEFF(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidListDin(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return ((i >= IDX_MIN) && ( i <= CAPACITY(l)));
}

boolean isIdxEffListDin(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
{
    return ((i >= IDX_MIN) && ( i <= NEFF(l)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyListDin(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{
    return NEFF(l) == 0;
}

boolean isFullListDin(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
    return NEFF(l) == CAPACITY(l);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readListDin(ListDin *l)
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{
    int N, i, element;
    scanf("%d", &N);
    while ( N < 0 || N > CAPACITY(*l))
    {
        scanf("%d", &N);
    }

    if (N != 0)
    {
        for (i = 0; i < N; i++)
        {
            scanf("%d", &element);
            ELMT(*l, i) = element;
        }
    }
    NEFF(*l) = N;
}

void printListDin(ListDin l)
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
{
    int i;

    if (isEmptyListDin(l))
    {
        printf("[]");
    } else 
    {
        printf("[");
        for (i = 0; i < NEFF(l); i++)
        {
            if (i != NEFF(l) - 1)
            {
                printf("%d", ELMT(l, i));
                printf(",");
            } else 
            {
                printf("%d", ELMT(l, listLengthListDin(l) - 1));
            }
        }
        printf("]");
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusListDin(ListDin l1, ListDin l2, boolean plus)
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
{
    int i;
    ListDin(l);
    CreateListDin(&l, NEFF(l1));
    NEFF(l) = NEFF(l1);
    CAPACITY(l) = CAPACITY(l1);

    if (plus)
    {
        for (i = 0; i < NEFF(l); i++)
        {
            ELMT(l, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    } else
    {
        for (i = 0; i < NEFF(l); i++)
        {
            ELMT(l, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return l;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqualListDin(ListDin l1, ListDin l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
{
    int i;
    if (NEFF(l1)!= NEFF(l2))
    {
        return false;
    } else
    {   
        for (i = 0; i < NEFF(l1); i++)
        {
            if (ELMT(l1, i) != ELMT(l2, i)) 
            {
                return false;
            }
        }
        return true;
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOfListDin(ListDin l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
{
    int i;
    if (isEmptyListDin(l))
    {
        return IDX_UNDEF;
    } else
    {
        for (i = 0; i < NEFF(l); i++)
        {
            if (ELMT(l, i) == val)
            {
                return i;
            }
        }
        return IDX_UNDEF;
    }
}

/* ********** NILAI EKSTREM ********** */
void extremeValuesListDin(ListDin l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
{
    int i;
    *max = ELMT(l, IDX_MIN);
    *min = ELMT(l, IDX_MIN);

    for (i = 0 + 1; i < NEFF(l); i++)
    {
        if (ELMT(l, i) > *max)
        {
            *max = ELMT(l, i);
        } if (ELMT(l, i) < *min)
        {
            *min = ELMT(l, i);
        }
    }
}

/* ********** OPERASI LAIN ********** */
void copyListDin(ListDin lIn, ListDin *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
{
    int i;

    CreateListDin(lOut, CAPACITY(lIn));
    for (i = 0; i < NEFF(lIn); i++)
    {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }

    NEFF(*lOut) = NEFF(lIn);
    CAPACITY(*lOut) = CAPACITY(lIn);
}

ElType sumListDin(ListDin l)
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
{
    int i;
    int sum = 0;

    if (isEmptyListDin(l))
    {
        return sum;
    } else
    {
        for (i = 0; i < NEFF(l); i++)
        {
            sum += ELMT(l, i);
        }
        return sum;
    }
}

int countValListDin(ListDin l, ElType val)
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
{
    int i;
    int count = 0;

    if(isEmptyListDin(l)) 
    {
        return count;
    } else
    {
        for (i = 0; i < NEFF(l); i++)
        {
            if (ELMT(l, i) == val)
            {
                count++;
            }
        }
        return count;
    }
}

/* ********** SORTING ********** */
void sortListDin(ListDin *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
    int i; 
    int j;
    int temp;

    // list kosong atau list berisi 1 tidak perlu diurutkan
    if (NEFF(*l) > 1)
    {
        if (asc) 
        {
            for (i = 0; i < NEFF(*l) - 1 ; i++)
            {
                for (j = 0; j < NEFF(*l) - 1 - i; j++)
                {
                    if(ELMT(*l, j) > ELMT(*l, j + 1))
                    {
                        temp = ELMT(*l, j);
                        ELMT(*l, j) = ELMT(*l, j + 1);
                        ELMT(*l, j + 1) = temp;
                    }
                }

            }
        } else
        {
            for (i = 0; i < NEFF(*l) - 1 ; i++)
            {
                for (j = 0; j < NEFF(*l) - 1 - i; j++)
                {
                    if(ELMT(*l, j) < ELMT(*l, j + 1))
                    {
                        temp = ELMT(*l, j);
                        ELMT(*l, j) = ELMT(*l, j + 1);
                        ELMT(*l, j + 1) = temp;
                    }
                }

            }
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListDin(ListDin *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    if (!isFullListDin(*l))
    {
        ELMT(*l, NEFF(*l)) = val;
        NEFF(*l) = NEFF(*l) + 1;
    }
}

void deleteLastListDin(ListDin *l, ElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
    if (!isEmptyListDin(*l))
    {
        *val = ELMT(*l, (NEFF(*l) - 1));
        NEFF(*l) = NEFF(*l) - 1;
    }
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDin(ListDin *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    CAPACITY(*l) = CAPACITY(*l) + num;
    BUFFER(*l) = realloc(BUFFER(*l), (CAPACITY(*l)) * sizeof(ElType));

}

void shrinkListDin(ListDin *l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
    CAPACITY(*l) = CAPACITY(*l) - num;
    BUFFER(*l) = realloc(BUFFER(*l), (CAPACITY(*l)) * sizeof(ElType));
}

void compressListDin(ListDin *l)
/* Proses : Mengubah capacity sehingga capacity = nEff */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */
{
    CAPACITY(*l) = NEFF(*l);
    BUFFER(*l) = realloc(BUFFER(*l), (CAPACITY(*l)) * sizeof(ElType));
}