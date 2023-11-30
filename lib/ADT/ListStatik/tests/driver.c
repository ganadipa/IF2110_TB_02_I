#include <stdio.h>
#include "../liststatik.h"

int main() {
    ListStatik l;
    int type;
    ElType val;

    scanf("%d", &type);

    switch (type) {
        case 1:
            // Test create and display an empty list
            CreateListStatik(&l);
            printListStatik(l);
            break;

        case 2:
            // Test insert elements and display
            CreateListStatik(&l);
            int n, elem;
            scanf("%d", &n);
            for(int i = 0; i < n; i++) {
                scanf("%d", &elem);
                insertLastStatik(&l, elem);
            }
            printListStatik(l);
            break;

        case 3:
            // Test searching an element
            CreateListStatik(&l);
            scanf("%d", &val);
            insertLastStatik(&l, val);
            printf("%d\n", indexOfListStatik(l, val));
            break;

        case 4:
            // Test deleting an element and display
            CreateListStatik(&l);
            insertLastStatik(&l, 10);
            insertLastStatik(&l, 20);
            deleteLastStatik(&l, &val);
            printListStatik(l);
            break;

        case 5:
            // Test sorting the list and display
            CreateListStatik(&l);
            insertLastStatik(&l, 30);
            insertLastStatik(&l, 10);
            insertLastStatik(&l, 20);
            sortListStatik(&l, true);
            printListStatik(l);
            break;

        case 6:
            // Test finding extreme values
            CreateListStatik(&l);
            insertLastStatik(&l, 5);
            insertLastStatik(&l, 1);
            insertLastStatik(&l, 3);
            ElType max, min;
            extremeValuesStatik(l, &max, &min);
            printf("Max: %d, Min: %d\n", max, min);
            break;


        default:
            printf("Invalid test case\n");
            break;
    }

    return 0;
}
