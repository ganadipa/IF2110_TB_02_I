#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "dsu.h"

// Function to create a new set with 'size' elements
void createSet(DisjointSet *ds) {
    int i;
    for (i = 1; i < 21;i++){
        ELMT_SET(*ds , i) = i;
    }
}

int findParent(DisjointSet *ds, int x){
    if ((*ds).arr[x] == x) {
        return x;
    }
    else {
        return findParent((*ds).arr[x], x);
    }
}

boolean check (DisjointSet *ds, int x, int y){
    return (findParent((*ds).arr[x], x) == findParent((*ds).arr[y], y)); 
}   

void Union(DisjointSet *ds, int x, int y){
    (*ds).arr[x] = findParent((*ds).arr[y], y);
}