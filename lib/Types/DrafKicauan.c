#include <stdio.h> 
#include "./DrafKicauan.h"

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
    TopDraf(*S)++; 
    InfoTopDraf(*S) = k; 
}

Kicauan ToDatabase(Kicauan k){
    return k;
} 

void PopDraf(DrafKicau *S, Kicauan *k){
    *k = InfoTopDraf(*S); 
    TopDraf(*S)--;
}
