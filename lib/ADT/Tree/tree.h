#ifndef TREE_H
#define TREE_H

#include "../../boolean.h"
#include "../ListDinamik/listdinamik.h"

typedef struct
{
    ListDin *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int capacity;   /* ukuran elemen */
} AdjacencyLists;


typedef struct tree {
    AdjacencyLists parentToChild; // tree 
    int numVertices;
    int maxVertices;
    int height;
} Tree;

#define PTC_ADJLISTS(t) (t).parentToChild
#define HEIGHT(t) (t).tree
#define MAXV(t) (t).maxVertices
#define NUMV(t) (t).numVertices

void createTree(Tree *t, int numNodes);

void addVertices_Tree(Tree *t);

void dfs_Tree(Tree t, int i, int depth);

void addChild_Trees(Tree *t, int parent, int child);


#endif
