#include <stdio.h>
#include "RequestQueue.h"

void createRequestQueue(RequestQueue *Q)

{
    HEAD_REQQUEUE(*Q) = NIL;
    TAIL_REQQUEUE(*Q) = NIL;
}

boolean isEmpty_RequestQueue(RequestQueue Q)

{
    return (HEAD_REQQUEUE(Q) == NIL && TAIL_REQQUEUE(Q) == NIL);
}

boolean isFull_RequestQueue(RequestQueue Q)

{
    return (TAIL_REQQUEUE(Q) + 1) % CAP_REQQUEUE == HEAD_REQQUEUE(Q);
}

int nbElmt_RequestQueue(RequestQueue Q)

{
    if (isEmpty_RequestQueue(Q)) return 0;


    if (HEAD_REQQUEUE(Q) <= TAIL_REQQUEUE(Q)) return TAIL_REQQUEUE(Q) - HEAD_REQQUEUE(Q) +1;
    else return TAIL_REQQUEUE(Q) - HEAD_REQQUEUE(Q) +1 + CAP_REQQUEUE;
}

void enqueue_RequestQueue(RequestQueue *Q, UserID u)

{
    if (isEmpty_RequestQueue(*Q)) {
        HEAD_REQQUEUE(*Q) = 0;
        TAIL_REQQUEUE(*Q) = 0;
        ELMT_REQQUEUE(*Q, 0) = u;
        return;
    }

    int ptr;
    for (ptr = TAIL_REQQUEUE(*Q); ptr != HEAD_REQQUEUE(*Q); ptr = (ptr -1) % CAP_REQQUEUE)
    {
        if (FRIENDCOUNT_REQQUEUE(ELMT_REQQUEUE(*Q, ptr)) < FRIENDCOUNT_REQQUEUE(u))
        {
            ELMT_REQQUEUE(*Q, (ptr + 1) % CAP_REQQUEUE) = ELMT_REQQUEUE(*Q, ptr); 
        } else 
        {
            ELMT_REQQUEUE(*Q, (ptr+1) % CAP_REQQUEUE) = u;
        }
    }

    if (FRIENDCOUNT_REQQUEUE(ELMT_REQQUEUE(*Q, ptr)) < FRIENDCOUNT_REQQUEUE(u))
    {
        ELMT_REQQUEUE(*Q, (ptr + 1) % CAP_REQQUEUE) = ELMT_REQQUEUE(*Q, ptr);
        ELMT_REQQUEUE(*Q, ptr) =  u;
    } else 
    {
        ELMT_REQQUEUE(*Q, (ptr+1) % CAP_REQQUEUE) = u;
    }

    TAIL_REQQUEUE(*Q) = (TAIL_REQQUEUE(*Q) + 1) % CAP_REQQUEUE;
}

void dequeque_RequestQueue(RequestQueue *Q, UserID *u)
{
    *u = ELMT_REQQUEUE(*Q, HEAD_REQQUEUE(*Q));

    if (HEAD_REQQUEUE(*Q) == TAIL_REQQUEUE(*Q)) {
        HEAD_REQQUEUE(*Q) = NIL;
        TAIL_REQQUEUE(*Q) = NIL;
    } else {
        HEAD_REQQUEUE(*Q) = (HEAD_REQQUEUE(*Q) + 1)% CAP_REQQUEUE;
    }
}

void removeElmt_RequestQueue(RequestQueue *Q, int idx)

{
    RequestQueue qtmp;
    createRequestQueue(&qtmp);
    int i = 0;

    while (!isEmpty_RequestQueue(*Q))
    {
        UserID u;
        dequeque_RequestQueue(Q, &u);

        if (i == idx) continue;

        ++i;
        enqueue_RequestQueue(&qtmp, u);
    }

    while (!isEmpty_RequestQueue(qtmp))
    {
        UserID u;
        dequeque_RequestQueue(&qtmp, &u);
        enqueue_RequestQueue(Q, u);
    }
}



int getIndex_RequestQueue(RequestQueue Q, int userID)

{
    if (isEmpty_RequestQueue(Q)) return NIL;

    int i = HEAD_REQQUEUE(Q);
    boolean found = false;
    while (!isEmpty_RequestQueue(Q) && !found) 
    {
        if (ID_REQQUEUE(ELMT_REQQUEUE(Q, i)) == userID)
        {
            found = true;
            continue;
        } 


        i = (i+1) % CAP_REQQUEUE;
        UserID u;
        dequeque_RequestQueue(&Q, &u);
    }

    


    if (found) return i;
    else return NIL;
}

void printRQ(RequestQueue rq)
{
    while (!isEmpty_RequestQueue(rq))
    {
        UserID u;

        dequeque_RequestQueue(&rq, &u);
        printf("%d %d\n", ID_REQQUEUE(u), FRIENDCOUNT_REQQUEUE(u));
    }
}


// int main(){
//     RequestQueue q;
//     createRequestQueue(&q);

//     UserID u;
//     ID_REQQUEUE(u) = 5;
//     FRIENDCOUNT_REQQUEUE(u) = 10;

//     enqueue_RequestQueue(&q, u);



//     ID_REQQUEUE(u) = 6;
//     FRIENDCOUNT_REQQUEUE(u) = 9;
//     enqueue_RequestQueue(&q, u);
//     printRQ(q);

//     UserID v;
//     dequeque_RequestQueue(&q, &v);
//     printf("head: %d\n", HEAD_REQQUEUE(q));
//     printf("tail: %d\n", TAIL_REQQUEUE(q));
//     printRQ(q);

//     printf("get index 5: %d\n", getIndex_RequestQueue(q, 5));
//     printf("nb elmt: %d\n", nbElmt_RequestQueue(q));
//     dequeque_RequestQueue(&q, &v);
//     printf("nb elmt: %d\n", nbElmt_RequestQueue(q));
//     printf("is empty: %d\n", isEmpty_RequestQueue(q));
//     printf("get idx 5: %d\n", getIndex_RequestQueue(q, 5));

    
//     return 0;
// }

