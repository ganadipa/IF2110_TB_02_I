#include <stdio.h>
#include "../tree.h"

int main()
{
    Tree l;
    int type, val;
    scanf("%d", &type);
    createTree(&l, 10);


    switch (type)
    {
    case 1:
        printf("%d", isFull_Tree(l));
        break;
    case 2:
        printf("%d", NUMV(l));
        addVertices_Tree(&l);
        printf(" %d", NUMV(l));
        break;
    case 3:
        createTree(&l, 5);
        addVertices_Tree(&l);
        addVertices_Tree(&l);
        addVertices_Tree(&l);
        addVertices_Tree(&l);
        addVertices_Tree(&l);
        addVertices_Tree(&l);
        addVertices_Tree(&l);
        addVertices_Tree(&l);
        addChild_Tree(&l, 0, 1);
        addChild_Tree(&l, 0, 2);
        addChild_Tree(&l, 0, 3);
        addChild_Tree(&l, 1, 4);
        addChild_Tree(&l, 1, 5);
        addChild_Tree(&l, 1, 6);
        addChild_Tree(&l, 1, 7);

        dfs_Tree(l, 0, 0);
        break;
    }

   
    return 0;
}