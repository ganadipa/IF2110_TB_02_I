#include "../string.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    String s;
    createEmptyString(&s, 350);
    stringAdd(&s, 'h');
    stringAdd(&s, 'e');
    stringAdd(&s, 'y');

    displayString(s);
    printf("%d", compareString(s, "hey"));
    return 0;
}
