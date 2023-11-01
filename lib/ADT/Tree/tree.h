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
    AdjacencyLists childToParent; // for dsu
    int numVertices;
    int maxVertices;
    int height;
} Tree;

#define PTC_ADJLISTS(t) (t).parentToChild
#define CTP_ADJLISTS(t) (t).childToParent
#define HEIGHT(t) (t).tree
#define MAXV(t) (t).maxVertices
#define NUMV(t) (t).numVertices

void createTree(Tree *t, int numNodes);

void addVertices(Tree *t);

void dfs(Tree t, int i, int depth);

void addChild(Tree *t, int parent, int child);


#endif