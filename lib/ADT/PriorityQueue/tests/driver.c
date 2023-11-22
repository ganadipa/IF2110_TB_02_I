#include <stdio.h>
#include "../prioqueue.h"

int main(){
    PrioQueueChar Q;
    MakeEmpty(&Q, 100);
    printf("Head : %d\n", Head(Q));
    printf("Tail : %d\n", Tail(Q));
    printf("MaxEl : %d\n", MaxEl(Q));
    PrintPrioQueueChar(Q);
    printf("\n");

    infotype X;
    Prio(X) = 10;
    Info(X) = 'C';

    Enqueue(&Q, X);

    printf("Head : %d\n", Head(Q));
    printf("Tail : %d\n", Tail(Q));
    printf("MaxEl : %d\n", MaxEl(Q));
    PrintPrioQueueChar(Q);
    printf("\n");

    Prio(X) = 3;
    Info(X) = 'C';

    Enqueue(&Q, X);

    Prio(X) = 10;
    Info(X) = 'A';

    Enqueue(&Q, X);

    printf("Head : %d\n", Head(Q));
    printf("Tail : %d\n", Tail(Q));
    printf("MaxEl : %d\n", MaxEl(Q));
    PrintPrioQueueChar(Q);
    printf("\n");


    Dequeue(&Q, &X);
    printf("Head : %d\n", Head(Q));
    printf("Tail : %d\n", Tail(Q));
    printf("MaxEl : %d\n", MaxEl(Q));
    PrintPrioQueueChar(Q);
    printf("\n");

    Enqueue(&Q, X);
    printf("Head : %d\n", Head(Q));
    printf("Tail : %d\n", Tail(Q));
    printf("MaxEl : %d\n", MaxEl(Q));
    PrintPrioQueueChar(Q);
    printf("\n");

}