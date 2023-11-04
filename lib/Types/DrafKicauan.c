#include "DrafKicauan.h"

void CreateDraf(DrafKicau *S){
    TopDraf(*S) = Nil; 
}

boolean isDrafEmpty(DrafKicau S){
    return TopDraf(S) == Nil;
}

void InisialisasiDrafKicau(Kicauan *k, int IDUser){
    userKicau(*k) = IDUser; 
    likeKicau(*k) = 0; 
}

void setDrafIDKicau(Kicauan *k, int IDKicau){
    IDKicau(*k) = IDKicau;
}

void PushDraf(DrafKicau *S, Kicauan k){
    if(isDrafEmpty(*S)){
        TopDraf(*S) = 0;
        InfoTopDraf(*S) = k;
    }
    else{
        TopDraf(*S) += 1; 
        InfoTopDraf(*S) = k; 
    }
}

void PopDraf(DrafKicau *S, Kicauan *k){
    *k = InfoTopDraf(*S); 
    if(TopDraf(*S) == 0){
        TopDraf(*S) = Nil;
    }
    else{
        TopDraf(*S) -= 1;
    }
}

void PrintDraf(DrafKicau S){
    Kicauan temp; 
    PopDraf(&S, &temp);
    displayString(temp.dateTime);
}
