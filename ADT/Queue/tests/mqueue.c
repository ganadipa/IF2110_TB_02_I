#include <stdio.h>
#include "../queue.h"

int main(){
    int type; 
    ElType input, input2; //
    int temp;
    Queue queue; 

    CreateQueue(&queue); 
    scanf("%d", &type);
    switch (type)
    {
    case 1:
        scanf("%d", &input);
        printf("%d", input); 
        break;
    case 2: 
        printf("%d", isEmpty(queue));
        break;
    case 3: 
        printf("%d", isFull(queue));
        break;
    case 4: 
        scanf("%d", &input);
        enqueue(&queue, input);
        printf("%d", length(queue)); 
        scanf("\n%d", &input2);
        enqueue(&queue, input2); 
        printf("%d", length(queue)); 
        break;
    case 5:
        displayQueue(queue);
        scanf("%d", &input);  
        enqueue(&queue, scanf("%d", &input));
        displayQueue(queue); 
        break;
    case 6: 
        scanf("%d", &input); 
        enqueue(&queue, input); 
        dequeue(&queue, &temp); 
        printf("%d", temp); 
        break; 
    case 7: 
        scanf("%d", &input); 
        printf("%d", input);  
        break;
    }
    return 0;
}