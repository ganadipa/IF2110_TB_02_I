#include <stdio.h>
#include "../stack.h"
#include <stdlib.h>

int main(){
    int type; 
    Stack stack; 
    CreateEmpty(&stack);
    infotype ingfo; 
    scanf("%d", &type);
    switch(type){
        //cek isEmpty 
        case 1: 
           printf("%d", IsEmpty(stack)); 
           break;
        case 2: 
            scanf("%d", &ingfo); 
            Push(&stack, ingfo); 
            printf("%d", IsEmpty(stack)); 
            break;
        //cek isFull
        case 3: 
            printf("%d", IsFull(stack)); 
            break;
        case 4: 
        
            break; 
        //case cek push  
        case 5: 
            scanf("%d", &ingfo); 
            Push(&stack, ingfo); 
            printf("%d", InfoTop(stack)); 
            break;
        //case cek pop 
        case 6:
            infotype temp; 
            scanf("%d", &ingfo); 
            Push(&stack, ingfo); 
            Pop(&stack, &temp); 
            printf("%d", temp); 
            break; 
    } 
    
    return 0;
}