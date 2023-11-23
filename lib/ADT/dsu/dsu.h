#ifndef DSU_H
#define DSU_H


#include "../../boolean.h"

typedef struct {
    int arr [20];
    int count;    
} DisjointSet;

#define ELMT_SET(ds, i) (ds).arr[(i)]

void addUser(DisjointSet *ds, int id);

void createSet(DisjointSet *ds);

int findParent(DisjointSet *ds, int x);

boolean check (DisjointSet *ds, int x, int y);

void Union(DisjointSet *ds, int x, int y);

#endif