#include <stdio.h>
#include "../queue.h"

int main(){
    int type; 
    ElType input, temp; 
    Queue ares; 

    CreateQueue(&ares); 
    scanf("%d", &type);
    switch (type)
    {
    case 1:
        scanf("%d", &input);
        printf("%d", input); 
        break;
    case 2: 
        printf("%d", isEmpty(ares));
        break;
    case 3: 
        printf("%d", isFull(ares));
        break;
    case 4: 
        scanf("%d", &input);
        enqueue(&ares, input);

        printf("%d\n", length(ares)); 
        scanf("%d", &input); 

        enqueue(&ares, input); 
        printf("%d", length(ares)); 
        break;
    case 5:
        displayQueue(ares);
        scanf("%d", &input);  
        enqueue(&ares, scanf("%d", &input));
        displayQueue(ares); 
        break;
    case 6: 
        scanf("%d", &input); 
        enqueue(&ares, input); 
        dequeue(&ares, &temp); 
        printf("%d", temp); 
        break; 
    case 7: 
        scanf("%d", &input); 
        printf("%d", input);  
        break;
    }
    return 0;
}