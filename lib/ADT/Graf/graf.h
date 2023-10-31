/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah integer */

#ifndef graf_H
#define graf_H

#include "../../boolean.h"
#include "../ListStatik/liststatik.h"

#define CAP 100

/**
 *  Definisi Graf : 
 * 1. numEdge menyatakan jumlah elemen
 * 2. numVertex menyatakan jumlah koneksi.
 * 3. adjMatrix menyatakan adjecency matrix.
*/
typedef int ElType;
typedef struct graf {
    int numEdges;
    int numVertices;
    int adjMatrix[CAP][CAP];
} Graf;

/**
 * List == Address == node()
*/

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateGraph(Graf *g) ;
/* I.S. sembarang             */
/* F.S. Terbentuk graf kosong */



/****************** TEST LIST KOSONG ******************/
boolean isEmpty_Graf(Graf g);
/* Mengirim true jika graf kosong */

boolean isFull_Graf(Graf  g);
/* Mengirim true jika graf full (numEdge == 0)*/

/****************** GETTER SETTER ******************/
ListStatik getAdjacencyList_Graf(Graf g, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void printGraph(Graf g);
/*
    I.S. Graf terdefinisi
    F.S. Output adjecency matriks hanya untuk index yang valid.
*/

boolean isDirectlyConnected_Graf(Graf g, int i, int j);

#endif