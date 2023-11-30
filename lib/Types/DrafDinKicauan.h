#ifndef DRAFDINKICAUAN 
#define DRAFDINKICAUAN 


#include "../boolean.h"
#include "../ADT/String/string.h"
#include "Kicauan.h"

typedef Kicauan infodraf; 

typedef struct nodeDraf* AddressDraf; 
typedef struct nodeDraf {
    infodraf kicau; 
    AddressDraf next;
} NodeDraf;

typedef struct {
    AddressDraf drafTop;
} DrafKicauDin; 

#define     NEXTDRAF(p) (p)->next
#define     INFODRAF(p) (p)->kicau
#define ADDR_TOPDRAF(s) (s).drafTop
#define      TOPDRAF(s) (s).drafTop->kicau


AddressDraf newNodeDraf(Kicauan kicau); 

boolean isDrafDinEmpty(DrafKicauDin s); 

void CreateDraftDin(DrafKicauDin *s);

void InisialisasiDrafDinKicau(Kicauan *k, int IDUser);

void PushDrafDin(DrafKicauDin *s, Kicauan kicau); 

void PopDrafDin(DrafKicauDin *s, Kicauan* kicau); 

int LengthDraf(DrafKicauDin s); 

#endif 