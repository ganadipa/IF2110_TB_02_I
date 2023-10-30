#include "../string.h"
#include <stdio.h>
// gcc -o driver driverstring.c ../string.c ../../WordMachine/wordmachine.c ../../WordMachine/charmachine.c
int main(int argc, char const *argv[])
{
    String s;
    createEmptyString(&s, 350);
    addChar(&s, 'h');
    addChar(&s, 'e');
    addChar(&s, 'y');

    displayString(s);
    printf("%d", compareStringInsensitively(s, "heY"));
    return 0;
}
