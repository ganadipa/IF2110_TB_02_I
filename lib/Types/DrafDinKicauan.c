#include "DrafDinKicauan.h"

void InitDrafKicau(Kicauan* k, int IDUser){
    userKicau(*k) = IDUser; 
    likeKicau(*k) = 0;
}

void setDrafIDDinKicau(Kicauan *k, int IDKicau){
    IDKicau(*k) = IDKicau;
}

AddressDraf newNodeDraf(Kicauan kicau){
    AddressDraf draf = (AddressDraf)malloc(sizeof(NodeDraf)); 
    if(draf != NULL){
        INFODRAF(draf) = kicau;
        NEXTDRAF(draf) = NULL; 
    }
    return draf;
}

boolean isDrafDinEmpty(DrafKicauDin s){
    return ADDR_TOPDRAF(s) == NULL;
}

void CreateDraftDin(DrafKicauDin *s){
    ADDR_TOPDRAF(*s) = NULL;
}

void InisialisasiDrafDinKicau(Kicauan *k, int IDUser){
    userKicau(*k) = IDUser; 
    likeKicau(*k) = 0; 
}

void PushDrafDin(DrafKicauDin *s, Kicauan kicau){

    AddressDraf draf = newNodeDraf(kicau); 
    if(isDrafDinEmpty(*s)){
        ADDR_TOPDRAF(*s) = draf; 
    } else{
        NEXTDRAF(draf) = ADDR_TOPDRAF(*s); 
        ADDR_TOPDRAF(*s) = draf;
    }
}

void PopDrafDin(DrafKicauDin *s, Kicauan* kicau){
    AddressDraf draf = ADDR_TOPDRAF(*s); 
    *kicau = TOPDRAF(*s);
    if(NEXTDRAF(draf) == NULL){
        ADDR_TOPDRAF(*s) = NULL; 
    } else{
        ADDR_TOPDRAF(*s) = NEXTDRAF(draf); 
    }
    free(draf);
}


int LengthDraf(DrafKicauDin s){
    int count = 0; 
    AddressDraf temp = ADDR_TOPDRAF(s); 
    while(temp != NULL){
        ++count; 
        temp = NEXTDRAF(temp);
    }
    return count;
    
}