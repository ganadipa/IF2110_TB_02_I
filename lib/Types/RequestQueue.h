#ifndef REQQUEUE_H
#define REQQUEUE_H
#include "../boolean.h"


#define infotype User

typedef struct {
    int friendCount;
    int userID;
} UserID;

#define ID_REQQUEUE(u) (u).userID
#define FRIENDCOUNT_REQQUEUE(u) (u).friendCount
#define CAP_REQQUEUE 20
#define NIL -1

typedef struct {
    int Head;
    int Tail;
    UserID T[CAP_REQQUEUE];
} RequestQueue;
/*
    Definisi RequestQueue: priority queue dengan jumlah teman sebagai pembanding.
*/

#define MAXELMT_REQQUEUE(Q) (Q).maxElmt
#define ELMT_REQQUEUE(Q,i) (Q).T[i]
#define HEAD_REQQUEUE(Q) (Q).Head
#define TAIL_REQQUEUE(Q) (Q).Tail

void createRequestQueue(RequestQueue *Q);

boolean isEmpty_RequestQueue(RequestQueue Q);

boolean isFull_RequestQueue(RequestQueue Q);

int nbElmt_RequestQueue(RequestQueue Q);

void enqueue_RequestQueue(RequestQueue *Q, UserID u);

void dequeque_RequestQueue(RequestQueue *Q, UserID *u);

void removeElmt_RequestQueue(RequestQueue *Q, int idx);


int getIndex_RequestQueue(RequestQueue Q, int userID);

#endif