/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah integer */

#ifndef graf_H
#define graf_H

#include "../../boolean.h"
#include "../ListStatik/liststatik.h"
#include "../Matriks/boolMatriks.h"

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
    BoolMatrix adjacencyMatrix;
} Graf;

#define NUMEDGE(g) (g).numEdges
#define NUMVERTICES(g) (g).numVertices
#define ADJMATRIX(g) (g).adjacencyMatrix
#define CONNECTED(g, i, j) ELMT_BoolMatriks((g).adjacencyMatrix,i,j)

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

void printGraph(Graf g);
/*
    I.S. Graf terdefinisi
    F.S. Output adjecency matriks hanya untuk index yang valid.
*/

boolean isDirectlyConnected_Graf(Graf g, int i, int j);
/**
 * g adalah graf tak berarah
*/


void addEdge(Graf *g, int i, int j);

void cutEdge(Graf *g, int i, int j);

int countConnections(Graf g, int t);

#endif