#include <stdio.h>
#include "../graf.h"

int main(int argc, char const *argv[])
{
    Graf g;
    CreateGraph(&g, 20);
    printf("%d", CONNECTED(g, 0, 0));
    addEdge(&g, 0, 0);
    addEdge(&g, 1, 0);
    printGraph(g);
    return 0;
}
