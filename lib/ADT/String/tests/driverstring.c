<<<<<<< HEAD
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
=======
#include "../string.h"
#include <stdio.h>
// cd lib/adt/string/tests
// gcc -o driver driverstring.c ../string.c ../../WordMachine/wordmachine.c ../../WordMachine/charmachine.c
int main(int argc, char const *argv[])
{
    String s;
    createEmptyString(&s, 350);
    displayString(s);
    printf("%d", compareStringInsensitively(s, ""));
    return 0;
}
>>>>>>> main
