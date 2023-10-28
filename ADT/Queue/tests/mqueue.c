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
        displayQueue(queue);
        break;
    case 2: 
        printf("%d", isEmpty(queue));
        scanf("%d", &input); 
        enqueue(&queue, input);
        printf("\r\n%d", isEmpty(queue));
        break;
    //check isFull is not doesnt full 
    case 3: 
        printf("%d", isFull(queue));
        break;
    case 4: 
        scanf("%d", &input);
        enqueue(&queue, input);
        printf("%d", length(queue)); 
        scanf("%d", &input2);
        enqueue(&queue, input2); 
        printf("\r\n%d", length(queue)); 
        break;
    //display queue check
    case 5:
        displayQueue(queue);
        scanf("%d", &input);  
        enqueue(&queue, input);
        displayQueue(queue); 
        break;
    //dequeue element check
    case 6: 
        scanf("%d", &input); 
        enqueue(&queue, input); 
        dequeue(&queue, &temp); 
        printf("%d", temp); 
        break; 
    //isFull check 
    case 7: 
        int a = 100;
        while(a--){
            scanf("%d", &input);
            enqueue(&queue, input);
        }
        printf("%d", isFull(queue));  
        break;
    }
    return 0;
}