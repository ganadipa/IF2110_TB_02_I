#include <stdio.h>
#include <stdlib.h>
#include "../../boolean.h"
#include "dsu.h"

#define MARK 999

// Function to create a new set with 'size' elements
void createSet(DisjointSet *ds) {
    int i;
    for (i = 0; i < 20;i++){
        ELMT_SET(*ds , i) = MARK;
    }
    ds -> count = 0;
}

void addUser(DisjointSet *ds, int id) {
    ds -> count++;
    ELMT_SET(*ds, id) = id;
}

int findParent(DisjointSet *ds, int x){
    if ((*ds).arr[x] == x) {
        return x;
    }
    else {
        return findParent(ds, ELMT_SET(*ds, x));
    }
}

boolean check (DisjointSet *ds, int x, int y){
    return findParent(ds, ELMT_SET(*ds, x)) == findParent(ds, ELMT_SET(*ds, y)); 
}   

void Union(DisjointSet *ds, int x, int y){
    (*ds).arr[x] = findParent(ds, ELMT_SET(*ds, y));
}
