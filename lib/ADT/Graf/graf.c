/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah integer */

#include <stdio.h>
#include "../../boolean.h"
#include "./graf.h"
/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateGraph(Graf *g) 
/* I.S. sembarang             */
/* F.S. Terbentuk graf kosong */
{
    NUMEDGE(*g) = 0;
    NUMVERTICES(*g) = 0;
    int i, j;
    for (i = 0; i < CAP; i++) {
        for (j = 0; j < CAP; j++) {
            CONNECTED(*g, i, j) = false;
        }
    }
}


/****************** TEST LIST KOSONG ******************/
boolean isFull_Graf(Graf g)
/* Mengirim true jika graf full */
{
    return  NUMVERTICES(g) = CAP;
}

boolean isEmpty_Graf(Graf  g)
/* Mengirim true jika graf kosong*/
{
    return NUMVERTICES(g) = 0;
}


void printGraph(Graf g)
/*
    I.S. Graf terdefinisi
    F.S. Output adjecency matriks hanya untuk index yang valid.
*/
{
    int i, j;
    for (i = 0; i < NUMVERTICES(g); i++) {
        printf("[");
        for (j = 0; j < NUMVERTICES(g); j++) {
            printf("%d", CONNECTED(g, i , j));
            if (j == NUMVERTICES(g) -1) printf("]");
            else printf(" ");
        }
        printf("\n");
    }
}

boolean isDirectlyConnected_Graf(Graf g, int i, int j)
/**
 * g adalah graf tak berarah
*/
{
    return CONNECTED(g, i , j) == true;
}

void addEdge(Graf *g, int i, int j) 
/**
 * I.S. i dan j kurang dari NUMVERTICES(*g)
*/
{
    NUMEDGE(*g) += 1;
    CONNECTED(*g, i, j) = true;
    CONNECTED(*g, j, i) = true;
}


int countConnections(Graf g, int i) {
    int k, count = 0;;
    for (k = 0; k < NUMEDGE(g); k++) {
        if (CONNECTED(g, i, k) == true && i != k) count++;
    }

    return count;
    
}

void removeEdge(Graf *g, int i, int j) 
/**
 * I.S. i dan j kurang dari NUMVERTICES(*g)
*/
{
    NUMEDGE(*g) -= 1;
    CONNECTED(*g, i, j) = false;
    CONNECTED(*g, j, i) = false;
}

void addVertices(Graf *g)

{
    NUMVERTICES(*g) += 1;
    addEdge(g, NUMVERTICES(*g)-1, NUMVERTICES(*g)-1);
}


