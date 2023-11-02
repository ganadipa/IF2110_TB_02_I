#ifndef REQQUEUE_H
#define REQQUEUE_H
#include "../boolean.h"
#include "./User.h"

#define IDX_UNDEF -1

#define Nil -1
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
typedef struct {
    User friend1; 
} infotype;

typedef int address;   /* indeks tabel */
/* Contoh deklarasi variabel bertype RequestQueue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct {
    infotype *T;   /* tabel penyimpan elemen */
    address HEAD;  /* alamat penghapusan */
    address TAIL;  /* alamat penambahan */
    int MaxEl;     /* Max elemen queue */
} RequestQueue;
/* Definisi RequestQueue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah RequestQueue, maka akses elemen : */
#define Friend1(e)     (e).friend1
#define Info(e)     (e).info
#define Head(Q)     (Q).HEAD
#define Tail(Q)     (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q)    (Q).MaxEl
#define Elmt(Q,i)   (Q).T[(i)]

/* ********* Prototype ********* */
boolean isEmptyRequestQueue (RequestQueue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */

boolean isFullRequestQueue  (RequestQueue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */

int NBElmtRequestQueue (RequestQueue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmptyRequestQueue (RequestQueue * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Primitif Add/Delete *** */
void EnqueueRequestQueue (RequestQueue * Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */

void DequeueRequestQueue (RequestQueue * Q, infotype * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

#endif