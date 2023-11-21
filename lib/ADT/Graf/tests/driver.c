#include <stdio.h>
#include "../graf.h"

int main(int argc, char const *argv[])
{
    Graf g;
    CreateGraph(&g);
    int type;
    scanf("%d", &type);
    int i;

    switch (type)
    {
    case 1:
        // Test createGraph
        CreateGraph(&g);
        printf("%d %d", isEmpty_Graf(g), isFull_Graf(g));
        break;
    case 2:
        // Test isfull, AddEdge
        int j;


        for (i = 0; i < CAP; i++)
        {   
            addVertices(&g);
            for (j = 0; j < CAP; j++)
            {
                
                addEdge(&g, i, j);
            }
        }
        printf("%d %d", isEmpty_Graf(g), isFull_Graf(g));

        break;
    case 3:
        // Test removeEdge, AddEdge, countConnections
        for (i = 0; i < 10; i++){
            addVertices(&g);
            addEdge(&g, 1, i+1);
        }

        printf("%d", countConnections(g, 1));
        removeEdge(&g, 1, 8);
        printf(" %d", countConnections(g,1));
    }
    
    printf("hello world!");
    return 0;
}
