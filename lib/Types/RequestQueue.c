#include <stdio.h>
#include <stdlib.h>
#include "RequestQueue.h"

/* ********* Prototype ********* */
/* *** Kreator *** */
void CreateQueue(RequestQueue *Q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
{
    Head_ReqQue(*Q) = IDX_UNDEF;
    Tail_ReqQue(*Q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmptyRequestQueue(RequestQueue Q)
/* Mengirim true jika q kosong: lihat definisi di atas */
{
    return (Head_ReqQue(Q) == IDX_UNDEF && Tail_ReqQue(Q) == IDX_UNDEF);
}
boolean isFullRequestQueue(RequestQueue Q)
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
{
    return (lengthRequestQueue(Q) == CAPACITY_REQQUEUE);
}

int lengthRequestQueue(RequestQueue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
{
    if(isEmptyRequestQueue(Q)){
        return 0;
    } else {
        if (Tail_ReqQue(Q) >= Head_ReqQue(Q)){ 
            return Tail_ReqQue(Q) - Head_ReqQue(Q) +1;
        }else{
            return Tail_ReqQue(Q) - Head_ReqQue(Q) + 1 + CAPACITY_REQQUEUE;
        }
    }
}
/* *** Primitif Add/Delete *** */
void enqueueRequestQueue(RequestQueue *Q, Friend F)
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
{
    int idx;
    int previdx;

    if (isEmptyRequestQueue(*Q)){
        Head_ReqQue(*Q) = 0;
        Tail_ReqQue(*Q) = 0;
        ELMT_ReqQue(*Q, Head(*Q)) = F;
    } else {
    }

    idx = Tail_ReqQue(*Q);
    while (idx != Head_ReqQue(*Q)){
        if (FRIENDCOUNT_REQQUEUE(ELMT_ReqQue(*Q, idx)) < FRIENDCOUNT_REQQUEUE(F))
        {
            ELMT_ReqQue(*Q, (idx + 1) % CAPACITY_REQQUEUE) = ELMT_ReqQue(*Q, F); 
        } else 
        {
            ELMT_ReqQue(*Q, (idx+1) % CAPACITY_REQQUEUE) = F;
        }
    }
    }
void dequeueRequestQueue(RequestQueue *Q, int *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */