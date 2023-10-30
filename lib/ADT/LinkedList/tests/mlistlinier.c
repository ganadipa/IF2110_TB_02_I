#include <stdio.h>
#include "../listlinier.h"

int main()
{
    List l;
    int type, val;
    scanf("%d", &type);
    CreateListLinier(&l);

    switch (type)
    {
    case 1:
        // Test insertFirst, insertLast, insertAt
        scanf("%d", &val);
        insertFirst_ListLinier(&l, val);
        insertFirst_ListLinier(&l, val+1);
        insertLast_ListLinier(&l, val+100);
        insertAt_ListLinier(&l, val+1000, 3);
        displayList_ListLinier(l);
        break;
    case 2:
        // Test deleteAt, deleteLast, deleteFirst
        scanf("%d", &val);
        insertFirst_ListLinier(&l, val);
        insertFirst_ListLinier(&l, val-1);
        insertFirst_ListLinier(&l, val-2);
        int _;
        deleteAt_ListLinier(&l, 1, &_);
        printf("%d", _);
        displayList_ListLinier(l);
        deleteFirst_ListLinier(&l, &_);
        printf("%d", _);
        displayList_ListLinier(l);
        deleteLast_ListLinier(&l, &_);
        printf("%d", _);
        displayList_ListLinier(l);
    }

    return 0;
}