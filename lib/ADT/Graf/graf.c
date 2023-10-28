/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah integer */


#include "../boolean.h"
#include "../ListStatik/liststatik.h"
#include "./graf.h"
/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateGraph(Graf *g) 
/* I.S. sembarang             */
/* F.S. Terbentuk graf kosong */
{
    g->numEdge = 0;
    g->numVertex = 0;
    int i, j;
    for (i = 0; i < CAP; i++) {
        for (j = 0; j < CAP; j++) {
            g->adjMatrix[i][j] = -1;
        }
    }
}


/****************** TEST LIST KOSONG ******************/
boolean isEmpty(Graf g)
/* Mengirim true jika graf kosong */
{
    return g.numEdge == 0;
}

boolean isFull(Graf  g)
/* Mengirim true jika graf full (numEdge == 0)*/
{
    return g.numEdge == 0;
}

/****************** GETTER SETTER ******************/
ListStatik getAdjacencyList(Graf g, int idx)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
{
    ListStatik l;
    CreateListStatik(&l);
    int i = 0;
    for (i = 0; i < CAP; i++) {
        if (g.adjMatrix[idx][i] == 1) insertLast(&l, i);
    }

    return l;
}

void printGraph(Graf g)
/*
    I.S. Graf terdefinisi
    F.S. Output adjecency matriks hanya untuk index yang valid.
*/
{
    int i, j;
    for (i = 0; i < g.numEdge; i++) {
        printf("[");
        for (j = 0; j < g.numEdge; j++) {
            printf("%d", g.adjMatrix);
            if (j == g.numEdge -1) printf("]");
            else printf(" ");
        }
    }
}

boolean isDirectlyConnected(Graf g, int i, int j)
/**
 * g adalah graf tak berarah
*/
{
    return g.adjMatrix[i][j] == 1;
}




