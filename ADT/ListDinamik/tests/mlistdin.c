#include <stdio.h>
#include "../listdin.h"

int main()
{
    int type;
    // int m, y;
    int x;
    int i;
    // int max, min;
    ListDin ld1;
    // ListDin ld2;

    scanf("%d", &type);

    switch (type)
    {
    case 1:
        // Test Create DateTime dan Print DateTime
        scanf("%d", &x);
        CreateListDin(&ld1, x);
        readListDin(&ld1);
        printListDin(ld1);
        break;

    case 2:
        // Test Hitung Length ListDin
        scanf("%d", &x);
        CreateListDin(&ld1, x);
        readListDin(&ld1);
        printf("%d", listLengthListDin(ld1));
        break;

    case 3:
        // Test Mencari First Index dan Last Index 
        // Test Mencari Index dan Jumlah Kemunculan dari Sebuah Elemen (jika ada)
        scanf("%d", &x);
        CreateListDin(&ld1, x);
        readListDin(&ld1);
        scanf("%d", &i);
        printf("%d", getFirstIdxListDin(ld1));
        printf("\n");
        printf("%d", getLastIdxListDin(ld1));
        printf("\n");
        printf("%d", indexOfListDin(ld1, i));
        printf("\n");
        printf("%d", countValListDin(ld1, i));
        break;

    // case 4:
    //     // Test Boolean
    //     scanf("%d", &x);
    //     CreateListDin(&ld1, x);
    //     readListDin(&ld1);
    //     scanf("%d", &i);
    //     printf("%d", isIdxValidListDin(ld1, i));  // true jika i adalah indeks yang valid untuk kapasitas list
    //     printf("%d", isIdxEffListDin(ld1, i));    // true jika i adalah indeks yang terdefinisi untuk list  
    //     printf("%d", isEmptyListDin(ld1));        // true jika list l kosong
    //     printf("%d", isFullListDin(ld1));         // true jika list l penuh
    //     break;

    // case 5:
    //     // Test Operasi Plus Minus 
    //     scanf("%d", &x);
    //     CreateListDin(&ld1, x);
    //     readListDin(&ld1);
    //     CreateListDin(&ld2, x);
    //     readListDin(&ld2);
    //     plusMinusListListDin(ld1, ld2, true);
    //     plusMinusListListDin(ld1, ld2, false);
    //     break;

    // case 6:
    //     // Test Mengecek Isi Kedua List
    //     scanf("%d", &x);
    //     CreateListDin(&ld1, x);
    //     readListDin(&ld1);
    //     CreateListDin(&ld2, x);
    //     readListDin(&ld2);
    //     isListEqualListDin(ld1, ld2);
    //     break;    

    // case 7:
    //     // Test Mencari Nilai Max
    //     scanf("%d", &x);
    //     CreateListDin(&ld1, x);
    //     readListDin(&ld1);
    //     extremeValuesListDin(ld1, &max, &min);
    //     printf("%d", &max);
    //     printf("%d", &min);
    //     break; 

    // case 8:
    //     // Test Copy List
    //     scanf("%d", &x);
    //     CreateListDin(&ld1, x);
    //     readListDin(&ld1);
    //     copyListDin(ld1, &ld2);
    //     printListDin(ld2);
    //     break; 

    // case 9:
    //     // Test Menambahkan Semua Elemen List
    //     scanf("%d", &x);
    //     CreateListDin(&ld1, x);
    //     readListDin(&ld1);
    //     sumListDin(ld1);
    //     break;    

    // case 10:
    //     // Test Sort List
    //     scanf("%d", &x);
    //     CreateListDin(&ld1, x);
    //     readListDin(&ld1);
    //     sortListDin(&ld1, true);    // ascending
    //     printListDin(ld1);
    //     sortListDin(&ld1, false);   // descending
    //     printListDin(ld1);
    //     break;

    // case 11:
    //     // Test Menambah dan Menghapus Elemen Terakhir
    //     scanf("%d", &x);
    //     CreateListDin(&ld1, x);
    //     readListDin(&ld1);
    //     scanf("%d", &i);
    //     insertLastListDin(&ld1, i);
    //     printListDin(ld1);
    //     deleteLastListDin(&ld1, &j);
    //     printListDin(ld1);
    //     break;    

    // case 12:
    //     // Test Mengubah Ukuran List
    //     scanf("%d", &x);
    //     CreateListDin(&ld1, x);
    //     readListDin(&ld1);
    //     expandListDin(&ld1, 3);
    //     printListDin(ld1);
    //     shrinkListDin(&ld1, 2);
    //     printListDin(ld1);
    //     compressListDin(&ld1);
    //     printListDin(ld1);
    //     break;       
    }

    return 0;
}