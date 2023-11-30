#ifndef REQQUEUE_H
#define REQQUEUE_H

#include "../boolean.h"

#define IDX_UNDEF -1
#define CAPACITY_REQQUEUE 20
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
typedef struct {
    int friendCount;
    int userID;
} Friend;
typedef struct {
    Friend F[CAPACITY_REQQUEUE];
    int Head;
    int Tail;     /* Max elemen queue */
} RequestQueue;

/* Definisi RequestQueue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define Head_ReqQue(Q) (Q).Head
#define Tail_ReqQue(Q) (Q).Tail
#define ELMT_ReqQue(Q,i) (Q).F[i]
#define ID_REQQUEUE(u) (u).userID
#define FRIENDCOUNT_REQQUEUE(u) (u).friendCount

/* *** Kreator *** */
void createRequestQueue(RequestQueue *Q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmptyRequestQueue(RequestQueue Q);

/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFullRequestQueue(RequestQueue Q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int lengthRequestQueue(RequestQueue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueueRequestQueue(RequestQueue *Q, Friend u);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeueRequestQueue(RequestQueue *Q, Friend *u);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

void removeElmt_RequestQueue(RequestQueue *Q, int idx);

int getIndex_RequestQueue(RequestQueue Q, int ID);




#endif