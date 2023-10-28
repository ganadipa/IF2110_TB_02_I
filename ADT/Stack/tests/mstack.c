#include "../stack.h"
#include <stdio.h>

int main(){
    int type; 
    infotype input; 
    Stack ares; 
    CreateEmpty(&ares);
    scanf("%d", &type);
    switch(type){
        //cek isEmpty 
        case 1: 
           printf("%d", IsEmpty(ares)); 
           break;
        case 2: 
            scanf("%d", &input); 
            Push(&ares, input); 
            printf("%d", IsEmpty(ares)); 
            break;
        //cek isFull
        case 3: 
            printf("%d", IsFull(ares)); 
            break;
        case 4: 
        
            break; 
        //case cek push  
        case 5: 
            scanf("%d", &input); 
            Push(&ares, input); 
            printf("%d", InfoTop(ares)); 
        //case cek pop 
        case 6:
            int temp; 
            scanf("%d", &input); 
            Push(&ares, input); 
            Pop(&ares, &temp); 
            printf("%d", temp); 
            break; 
    } 
    
    return 0;
}