#include <stdio.h>
#include "../datetime.h"

int main()
{
    int type;
    int m, y;
    long x;
    DATETIME d1;
    DATETIME d2;

    scanf("%d", &type);

    switch (type)
    {
    case 1:
        // Test Mencari Maximum Hari
        scanf("%d", m);
        scanf("%d", y);
        GetMaxDay(m, y);
        break;

    case 2:
        // Test Create DateTime dan Print DateTime
        BacaDATETIME(&d1);
        TulisDATETIME(d1);
        break;

    case 3:
        // Test Boolean
        BacaDATETIME(&d1);
        BacaDATETIME(&d2);
        DEQ(d1, d2);    // true jika D1=D2
        DNEQ(d1, d2);   // true jika D1!=D2
        DLT(d1, d2);    // true jika D1<D2
        DGT(d1, d2);    // true jika D1>D2
        break;

    case 4:
        // Test DateTime Next NDetik dan Prev NDetik
        BacaDATETIME(&d1);
        scanf("%d", &x);
        DATETIMENextNDetik(d1, x);
        DATETIMEPrevNDetik(d1, x);
        break;

    case 5:
        // Test DateTime Durasi
        BacaTIME(&d1);
        BacaTIME(&d2);
        DATETIMEDurasi(d1, d2);
        break;
    }

    return 0;
}