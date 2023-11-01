#include <stdio.h>
#include "../time.h"

int main()
{
    int type;
    long x;
    TIME t1;
    TIME t2;

    scanf("%d", &type);

    switch (type)
    {
    case 1:
        // Test Create Time dan Print Time
        BacaTIME(&t1);
        TulisTIME(t1);
        break;

    case 2:
        // Test Ubah Time Ke Detik
        BacaTIME(&t1);
        TIMEToDetik(t1);
        break;

    case 3:
        // Test Ubah Time Ke Detik
        BacaTIME(&t1);
        TIMEToDetik(t1);
        break;

    case 4:
        // Test Ubah Detik Ke Time
        scanf("%d", &x);
        DetikToTIME(x);
        break;

    case 5:
        // Test Boolean
        BacaTIME(&t1);
        BacaTIME(&t2);
        TEQ(t1, t2);    // true jika T1=T2
        TNEQ(t1, t2);   // true jika T1!=T2
        TLT(t1, t2);    // true jika T1<T2
        TGT(t1, t2);    // true jika T1>T2
        break;

    case 6:
        // Test Next Detik dan Prev Detik
        BacaTIME(&t1);
        NextDetik(t1);
        PrevDetik(t1);
        break;

    case 7:
        // Test Next NDetik dan Prev NDetik
        BacaTIME(&t1);
        scanf("%d", &x);
        NextNDetik(t1, x);
        PrevNDetik(t1, x);
        break;

    case 8:
        // Test Time Durasi
        BacaTIME(&t1);
        BacaTIME(&t2);
        Durasi(t1, t2);
        break;
    }

    return 0;
}