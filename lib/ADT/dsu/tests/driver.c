#include "../dsu.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    DisjointSet dsu;
    int i;
    createSet(&dsu);
    addUser(&dsu, 0);
    addUser(&dsu, 1);
    addUser(&dsu, 2);

    Union(&dsu, 0, 1);
    printf("%d", check(&dsu, 0, 1));

    printf("parent : %d\n", findParent(&dsu, 0));
    
    for (i = 0 ; i < 20; i++) {
        printf("%d\n", dsu.arr[i]);
    }
    return 0;
}
