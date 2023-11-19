#include <stdio.h>
#include "prioqueue.h"
#include <stdlib.h>


/* ********* Prototype ********* */
boolean IsEmpty_PrioQueue (PrioQueueChar Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return Head(Q) == Nil && Tail(Q) == Nil;
}
boolean IsFull_PrioQueue (PrioQueueChar Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return ((Tail(Q)+1) % MaxEl(Q)) == Head(Q);
}
int NBElmt_PrioQueue (PrioQueueChar Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (IsEmpty_PrioQueue(Q)) return 0;
    else {
        if (Head(Q) >= Tail(Q)) return (Tail(Q) - Head(Q) + 1);
        else {
            return Tail(Q) - Head(Q) + MaxEl(Q) + 1;
        }
    }
}

/* *** Kreator *** */
void MakeEmpty_PrioQueue (PrioQueueChar * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    Q -> T = (infotype *) malloc((Max)*sizeof(infotype));
    if ((Q -> T )== NULL) {
        MaxEl(*Q) = 0;
    } else {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
        MaxEl(*Q) = Max;
    }
    
}

/* *** Destruktor *** */
void DeAlokasi_PrioQueue(PrioQueueChar * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    free(Q->T);
    MaxEl(*Q) = Nil;
    Head(*Q) = Nil;
    Tail(*Q) = 0;
}

/* *** Primitif Add/Delete *** */
void Enqueue_PrioQueue (PrioQueueChar * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{
    if (IsEmpty_PrioQueue(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        Q -> T[0] = X;
        return;
    }

    int ptr = Head(*Q);
    while (Prio(X) >= Prio(Elmt(*Q, ptr))) {
        if (ptr == Tail(*Q)) {
            ptr = (ptr + 1) % MaxEl(*Q);
            break;
        }

        ptr = (ptr + 1) % MaxEl(*Q);

    }

    if (ptr == (Tail(*Q) + 1)%MaxEl(*Q)) {
        Q -> T[ptr] = X;
        Tail(*Q) = (Tail(*Q) + 1) % MaxEl(*Q);
        return;
    }


    int i;
    for (i = Tail(*Q); i != ptr; i = ((i-1+MaxEl(*Q)) % MaxEl(*Q))) 
    {
        Q -> T[(i+1) % MaxEl(*Q)] = Q -> T[i];
    }

    Q -> T[(ptr + 1) % MaxEl(*Q)] = Q -> T[ptr];

    Q -> T[ptr] = X;

    Tail(*Q) = (Tail(*Q) + 1) % MaxEl(*Q);

    
}
void Dequeue_PrioQueue (PrioQueueChar * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    *X = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q)) {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        Head(*Q) = (Head(*Q) + 1)% MaxEl(*Q);
    }
}

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
    if (IsEmpty_PrioQueue(Q)) return;
    int i;
    for(i = Head(Q); i != Tail(Q); i = (i+1) % MaxEl(Q)){
        printf("%d %c\n", Prio(Elmt(Q, i)), Info(Elmt(Q, i)));
    }
    printf("%d %c\n", Prio(Elmt(Q, i)), Info(Elmt(Q, i)));
    printf("#\n");
}
