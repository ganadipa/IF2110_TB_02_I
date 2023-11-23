#include <stdio.h>
#include "../listdinamik.h"

int main()
{
    int x;
    ListDin ld1;
    ListDin l1, l2, l3;
    int type, val;

    scanf("%d", &type);

    switch (type)
    {
    case 1:
        // Test create and display an empty list
        CreateListDin(&l1, 10);
        printListDin(l1);
        dealocateListDin(&l1);
        break;

    case 2:
        // Test insert elements and display
        CreateListDin(&l1, 10);
        int n, elem;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &elem);
            insertLastListDin(&l1, elem);
        }
        printListDin(l1);
        dealocateListDin(&l1);
        break;

    case 3:
        // Test searching an element
        CreateListDin(&l1, 10);
        scanf("%d", &val);
        insertLastListDin(&l1, val);
        printf("%d\n", indexOfListDin(l1, val));
        dealocateListDin(&l1);
        break;

    case 4:
        // Test deleting an element and display
        CreateListDin(&l1, 10);
        insertLastListDin(&l1, 10);
        insertLastListDin(&l1, 20);
        deleteLastListDin(&l1, &val);
        printListDin(l1);
        dealocateListDin(&l1);
        break;

    case 5:
        // Test sorting the list and display
        CreateListDin(&l1, 10);
        insertLastListDin(&l1, 30);
        insertLastListDin(&l1, 10);
        insertLastListDin(&l1, 20);
        sortListDin(&l1, true);
        printListDin(l1);
        dealocateListDin(&l1);
        break;

    case 6:
        // Test finding extreme values
        CreateListDin(&l1, 10);
        insertLastListDin(&l1, 5);
        insertLastListDin(&l1, 1);
        insertLastListDin(&l1, 3);
        ElType max, min;
        extremeValuesListDin(l1, &max, &min);
        printf("Max: %d, Min: %d\n", max, min);
        dealocateListDin(&l1);
        break;

    case 7:
        // Test plusMinusListDin
        CreateListDin(&l1, 5);
        CreateListDin(&l2, 5);
        insertLastListDin(&l1, 1);
        insertLastListDin(&l1, 2);
        insertLastListDin(&l2, 3);
        insertLastListDin(&l2, 4);
        l3 = plusMinusListDin(l1, l2, true);
        printListDin(l3);
        dealocateListDin(&l1);
        dealocateListDin(&l2);
        dealocateListDin(&l3);
        break;

    case 8:
        // Test Create DateTime dan Print DateTime
        scanf("%d", &x);
        CreateListDin(&ld1, x);
        readListDin(&ld1);
        printListDin(ld1);
        break;

    case 9:
        // Test Hitung Length ListDin
        scanf("%d", &x);
        CreateListDin(&ld1, x);
        readListDin(&ld1);
        printf("%d", listLengthListDin(ld1));
        break;
    }

    return 0;
}