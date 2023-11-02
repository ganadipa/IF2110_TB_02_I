#include <stdio.h>
#include <stdlib.h>
#include "RequestQueue.h"
#include "User.h"

/* ********* Prototype ********* */
boolean isEmptyRequestQueue (RequestQueue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean isFullRequestQueue  (RequestQueue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return(NBElmtRequestQueue(Q) == MaxEl(Q));
}

int NBElmtRequestQueue (RequestQueue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (isEmptyRequestQueue(Q)){
        return 0 ;
    }else{
        if((Tail(Q) - Head(Q)) >= 0){
            return Tail(Q) - Head(Q) + 1; 
        }else{
            return MaxEl(Q) - (Head(Q) - (Tail(Q) + 1));
        }
    }
}

/* *** Kreator *** */
void MakeEmptyRequestQueue (RequestQueue *Q, int Max)
/* I.S. sembarang */
/* F.S. Terbentuk Queue dinamis Q kosong dengan kapasitas Max */
{
    (*Q).T = (infotype*) malloc ((Max) * sizeof(infotype));
    MaxEl(*Q) = Max;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

/* *** Primitif Add/Delete *** */
void EnqueueRequestQueue (RequestQueue *Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{
    int i;
    int j;
    int idx;
    int prevIdx;

    
    if (isEmptyRequestQueue(*Q)){
        Head(*Q) = 0;
        Tail(*Q) = 0;
        Elmt(*Q, Head(*Q)) = X;

    } else {
        Tail(*Q) += 1;
        Elmt(*Q,Tail(*Q)) = X;
    }
    idx = Tail(*Q);

    while (idx != Head(*Q)){
        if (idx == 0){
            prevIdx = MaxEl(*Q) - 1;
        } else {
            prevIdx = idx - 1;
        }

        if (FRIEND_COUNT(Friend1(Elmt(*Q, idx))) < FRIEND_COUNT(Friend1(Elmt(*Q, prevIdx)))){
            infotype temp = Elmt(*Q, prevIdx);
            Elmt(*Q, prevIdx) = Elmt(*Q, idx);
            Elmt(*Q, idx) = temp;
        }
        idx = prevIdx;
    }

    
}

void DequeueRequestQueue (RequestQueue *Q, infotype *X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    int i;
    *X = Elmt(*Q, Head(*Q));

    if (Head(*Q) == Tail(*Q)){
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        Head(*Q) = (Head(*Q) + 1) % MaxEl(*Q); 
    }
}