#include <stdio.h>
#include "listlinier.h"

int main(int argc, char const *argv[])
{
    List l;
    CreateListLinier(&l);
    insertFirst_ListLinier(&l, 1);
    insertFirst_ListLinier(&l, 2);
    insertFirst_ListLinier(&l, 3);
    displayList_ListLinier(l);

    return 0;
}
