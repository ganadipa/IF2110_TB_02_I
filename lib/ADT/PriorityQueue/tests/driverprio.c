#include <stdio.h>
#include "prioqueue.h"
#include <stdlib.h>

int main() {
    PrioQueueChar Q;
    infotype X;
    int type, maxEl, prio;
    char elem;

    scanf("%d", &type);

    switch (type) {
        case 1:
            // Test creating a priority queue and printing its elements
            scanf("%d", &maxEl);
            MakeEmpty_PrioQueue(&Q, maxEl);
            printf("Created Priority Queue with MaxEl=%d\n", maxEl);
            PrintPrioQueueChar(Q);
            break;

        case 2:
            // Test enqueuing elements and printing the queue
            scanf("%d", &maxEl);
            MakeEmpty_PrioQueue(&Q, maxEl);
            while (scanf("%d %c", &prio, &elem) != EOF) {
                X.prio = prio;
                X.info = elem;
                Enqueue_PrioQueue(&Q, X);
            }
            PrintPrioQueueChar(Q);
            break;

        case 3:
            // Test dequeuing elements and printing the queue
            scanf("%d", &maxEl);
            MakeEmpty_PrioQueue(&Q, maxEl);
            for (int i = 0; i < maxEl; i++) {
                scanf("%d %c", &prio, &elem);
                X.prio = prio;
                X.info = elem;
                Enqueue_PrioQueue(&Q, X);
            }
            Dequeue_PrioQueue(&Q, &X);
            printf("Dequeued: %d %c\n", X.prio, X.info);
            PrintPrioQueueChar(Q);
            break;
    }

    DeAlokasi_PrioQueue(&Q);
    return 0;
}
