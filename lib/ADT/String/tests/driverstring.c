#include "../string.h"
#include <stdio.h>
// cd lib/adt/string/tests
// gcc -o driver driverstring.c ../string.c ../../WordMachine/wordmachine.c ../../WordMachine/charmachine.c
int main(int argc, char const *argv[])
{
    String s;
    readString(&s, 350);
    displayString(s);
    printf("%d", stringToInt(s));
    return 0;
}
