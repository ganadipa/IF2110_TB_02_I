#include <stdio.h>
#include <stdlib.h>
#include "RequestQueue.h"

/* ********* Prototype ********* */
/* *** Kreator *** */
void createRequestQueue(RequestQueue *Q)
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

{
    int idx;
    int previdx;

    if (isEmptyRequestQueue(*Q)){
        Head_ReqQue(*Q) = 0;
        Tail_ReqQue(*Q) = 0;
        ELMT_ReqQue(*Q, 0) = F;
    }

    idx = Tail_ReqQue(*Q);
    while (idx != Head_ReqQue(*Q)){
        if (FRIENDCOUNT_REQQUEUE(ELMT_ReqQue(*Q, idx)) < FRIENDCOUNT_REQQUEUE(F))
        {
            ELMT_ReqQue(*Q, (idx + 1) % CAPACITY_REQQUEUE) = ELMT_ReqQue(*Q, idx); 
        } else {
            ELMT_ReqQue(*Q, (idx  +1) % CAPACITY_REQQUEUE) = F;
        }
        idx = (idx + CAPACITY_REQQUEUE - 1) % CAPACITY_REQQUEUE;
    }

    if(Head_ReqQue(*Q) == Tail_ReqQue(*Q)){
        if (FRIENDCOUNT_REQQUEUE(ELMT_ReqQue(*Q, Tail_ReqQue(*Q))) < FRIENDCOUNT_REQQUEUE(F)){
            ELMT_ReqQue(*Q, ((Tail_ReqQue(*Q) + 1) % CAPACITY_REQQUEUE)) = ELMT_ReqQue(*Q, Tail_ReqQue(*Q));
            ELMT_ReqQue(*Q, Tail_ReqQue(*Q)) =  F;
        } else {
            ELMT_ReqQue(*Q, (Tail_ReqQue(*Q)+1) % CAPACITY_REQQUEUE) = F;
        }
        Tail_ReqQue(*Q) = (Tail_ReqQue(*Q) + 1) % CAPACITY_REQQUEUE;
    }
}   

void dequeueRequestQueue(RequestQueue *Q, Friend *F)

{
    *F = ELMT_ReqQue(*Q, Head_ReqQue(*Q));

    if (Head_ReqQue(*Q) == Tail_ReqQue(*Q)) {
        Head_ReqQue(*Q) = IDX_UNDEF;
        Tail_ReqQue(*Q) = IDX_UNDEF;
    } else {
        Head_ReqQue(*Q) = (Head_ReqQue(*Q) + 1)% CAPACITY_REQQUEUE;
    }
}

void removeElmt_RequestQueue(RequestQueue *Q, int idx)
{
    int i = 0;
    RequestQueue QTemp;
    createRequestQueue(&QTemp);

    while (!isEmptyRequestQueue(*Q))
    {
        Friend F;
        dequeueRequestQueue(Q, &F);

        if (i == idx){
            continue;
        }
        ++i;
        enqueueRequestQueue(&QTemp, F);
    }

    while (!isEmptyRequestQueue(QTemp))
    {
        Friend F;
        dequeueRequestQueue(&QTemp, &F);
        enqueueRequestQueue(Q, F);
    }
}

int getIndex_RequestQueue(RequestQueue Q, int ID)
{
    if (isEmptyRequestQueue(Q)){
        return IDX_UNDEF;
    }

    int i = Head_ReqQue(Q);
    boolean found = false;
    while (!isEmptyRequestQueue(Q) && !found) 
    {
        if (ID_REQQUEUE(ELMT_ReqQue(Q, i)) == ID)
        {
            found = true;
            continue;
        } 
        i = (i+1) % CAPACITY_REQQUEUE;
        Friend F;
        dequeueRequestQueue(&Q, &F);
    }

    if (found) {
        return i;
    }else{ 
        return IDX_UNDEF;
    }
}

void displayRequestQueue(RequestQueue Q, ListUser l)

{
    int nb = lengthRequestQueue(Q);
    printf("\nTerdapat %d permintaan pertemanan untuk Anda.\n", nb);

    while (!isEmptyRequestQueue(Q))
    {
        Friend F;
        dequeueRequestQueue(&Q, &F);
        User u = ELMT_LISTUSER(l, ID_REQQUEUE(F));
        printf("\n | Nama: ");
        displayString(NAME(u));
        printf("\n | Jumlah teman: %d\n", FRIEND_COUNT(u));
    }
}