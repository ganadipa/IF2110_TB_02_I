#include <stdio.h>
#include "../string.h"

int main(int argc, char const *argv[])
{
    START();
    String s;
    createEmptyString(&s, 350);

    String s1;
    createEmptyString(&s, 350);

    String s2;
    createEmptyString(&s, 350);

    int type;
    scanf("%d",&type);
    switch (type)
    {
    case 1:
        // display empty string;
        displayString(s);
        break;
    case 2:
        // display the input
        readString(&s, 350);
        displayString(s);
        break;
    case 3:
        // is string equal
        readString(&s1, 350);
        readString(&s2, 350);
        displayString(s1);
        printf("%d", stringLength(s1));
        displayString(s2);
        printf("%d", stringLength(s2));
        printf("%d", isStringEqual(s1,s2));
        break;
    case 4:
        // output "aqi"
        addChar(&s, 'a');
        addChar(&s, 'q');
        addChar(&s, 'i');
        displayString(s);
        break;
    case 5:
        // check if the input string equal to "hello"
        readString(&s, 350);
        displayString(s); 
        printf("\n");
        printf("%d\n", compareString(s, "hello"));
        break;
    
    case 6:
        // two inputs (from two different methods), concatenate them.
        readString(&s, 350);
        ADV();
        ADVWORD();
        addWord(&s, currentWord);
        displayString(s);
        break;

    default:
        break;
    }

    CLOSE();
    return 0;
}
