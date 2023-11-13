

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void createTree(Tree *t, int capacity)
{
    PTC_ADJLISTS(*t).buffer = (ListDin *) malloc((capacity)*(sizeof (ListDin)));
    t -> height = 0;

    int i;
    for (i = 0; i < capacity; i++) {
        CreateListDin(&PTC_ADJLISTS(*t).buffer[i], capacity - 1);
    }

    MAXV(*t) = capacity;
    NUMV(*t) = 0;

}


boolean isFull_Tree(Tree t)
{
    return (MAXV(t) == NUMV(t));
}

void addVertices_Tree(Tree *t)
{
    if (!isFull_Tree(*t)) {
        NUMV(*t) += 1;
    } else {
        Tree tmp;
        createTree(&tmp, 2*MAXV(*t));
        
        int i;
        for (i = 0; i < MAXV(*t); i++) {
            int j;
            int neff_i = PTC_ADJLISTS(*t).buffer[i].nEff;
            for (j = 0; j < neff_i; j++) {
                ELMT(PTC_ADJLISTS(tmp).buffer[i], j) = ELMT(PTC_ADJLISTS(*t).buffer[i], j);
            }
        }

        *t = tmp;
    }
}

void addChild_Tree(Tree *t, int parent, int child)
{
    AdjacencyLists adj1 = PTC_ADJLISTS(*t);

    int i = indexOfListDin(adj1.buffer[parent], child);
    if (i != -1) {
        // do nothing
    } else {
        insertLastListDin(&adj1.buffer[parent], child);
    }


}

void dfs_Tree(Tree t, int i, int depth)

{
    int k;
    for (k = 0; k < depth; k++) {
        printf("-");
    }
    printf(">");
    
    printf("%d\n", i);
    AdjacencyLists adj1 = PTC_ADJLISTS(t);
    int neff = adj1.buffer[i].nEff;

    int j;
    for (j = 0; j < neff; j++) {
        int n = adj1.buffer[i].buffer[j];
        dfs_Tree(t, n, depth + 1);
    }
}

// int main(int argc, char const *argv[])
// {
//     Tree t;
//     createTree(&t, 5);
//     addVertices_Tree(&t);
//     addVertices_Tree(&t);
//     addVertices_Tree(&t);
//     addVertices_Tree(&t);
//     addVertices_Tree(&t);
//     addVertices_Tree(&t);
//     addVertices_Tree(&t);
//     addVertices_Tree(&t);
//     addChild_Tree(&t, 0, 1);
//     addChild_Tree(&t, 0, 2);
//     addChild_Tree(&t, 0, 3);
//     addChild_Tree(&t, 1, 4);
//     addChild_Tree(&t, 1, 5);
//     addChild_Tree(&t, 1, 6);
//     addChild_Tree(&t, 1, 7);

//     dfs(t, 0, 0);


//     return 0;
// }