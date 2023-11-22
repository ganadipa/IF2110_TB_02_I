#include <stdio.h>
#include "utas.h"
#include "../../listUtas.h"
void insertUtas_withIDKicau(Application *app, int IDKicau){
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
    if ( (KICAUAN(*app).nEff) < IDKicau ){
        printf("Tidak ditemukan kicauan dengan ID = %d\n", IDKicau);
        return;
    }
    if (IDKicau <1){
        printf("Kamu tidak bisa menambah Utas dengan id kicau %d", IDKicau);
        return;
    }
    // printf("%d\n", ELMT(KICAUAN(*app), IDKicau - 1).IDUtas);
    if (ELMT(KICAUAN(*app), IDKicau - 1).IDUtas != 0)
    {
        printf("Kicauan ini sudah menjadi kicauan utama dari utas lain.");
        return;
    }
    if (LOGINID(*app) == ELMT(KICAUAN(*app), IDKicau - 1).IDuser  ){
        printf("Utas Berhasil Dibuat!\n");
        String teksBaru;
        createEmptyString(&teksBaru, 280);
        boolean again = false;
        int i = 1;
        do
        {
            printf("Kicauan yang dimasukkan terpotong secara otomatis apabila jumlah karakter lebih dari 280.\n");
            printf("Masukkan Kicauan : ");
            readString(&teksBaru, 280);
            String namaUser = returnUsername(*app, LOGINID(*app));
            DATETIME formatIntTanggal = currentDateTime ();
            String waktu = DateTimeToString(formatIntTanggal);
            int IDUtasBaru = JUMLAHUTAS(*app) + 1;
            AddressUtas NewNode = newNodeUtas(teksBaru, namaUser, waktu);
            if (again && i!=1 ){
                insertAtAnakUtas( &ELMT(KICAUAN(*app), IDKicau-1), i, teksBaru, namaUser , waktu);
            }else if (i==1){
                FIRST(ELMT(KICAUAN(*app)  , IDKicau -1) ) = NewNode;
                JUMLAHUTAS(*app) = JUMLAHUTAS(*app) + 1;
                IDUTAS(ELMT(KICAUAN(*app), IDKicau - 1)) = IDUtasBaru;
                LEN_ANAKUTAS(ELMT(KICAUAN(*app), IDKicau - 1)) = LEN_ANAKUTAS(ELMT(KICAUAN(*app), IDKicau - 1)) + 1;
            }
            printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)");
            String lanjutlagi;
            createEmptyString(&teksBaru, 5);
            readString(&lanjutlagi, 5);
            again= compareStringInsensitively(lanjutlagi, "YA");
            i++;
        } while (again);

        printf("Utas selesai!\n");
        
        }
    else{
        printf("Kamu hanya bisa mengubah kicauan milikmu sendiri\n");
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void deleteAt_Utas(Application *app, int IDUtas, int indeksUtas){
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
    if (IDUtas <1){
        printf("Kamu tidak bisa menghapus Utas dengan id utas %d", IDUtas);
        return;
    }
    if (indeksUtas < 1 ){
        printf("Kamu tidak bisa menghapus Utas dengan indeks %d", indeksUtas);
        return;
    }
    int length = KICAUAN(*app).nEff;
    int i = 0;
    boolean found=false;
    while (!found && i<length ){
        if (ELMT( KICAUAN(*app),i ).IDUtas == IDUtas)
        {
            found = true;
        }
        i++;
    }
    if (!found){
        printf("Tidak ditemukan Utas dengan ID Utas %d\n", IDUtas);
        return;}
    i--;
    if (LOGINID(*app) != ELMT(KICAUAN(*app), i ).IDuser ){
        printf("Kamu hanya bisa menghapus utas milikmu sendiri\n");
        return;
    }
    if (indeksUtas == 0){
        printf("Kamu tidak bisa menghapus kicauan utama");
        return;}
    
    if (ELMT( KICAUAN(*app), i).lenUtas < indeksUtas){
        printf("Tidak ditemukan indeks Utas dengan indeks %d\n ", indeksUtas);
        return;
    }                                        

    String teks, nama, datetime;
    deleteAtAnakUtas(&ELMT(KICAUAN(*app), i), indeksUtas, &teks, &nama, &datetime);
    
    printf("Utas berhasil dihapus!");
}
//MEnghapus anak Utas berdasarkan ID UTAS, TIDAK BISA MENGHAPUS UTAS PERTAMA

void NyambungAnakUtas(Application *app, int IDUtas, int indeksUtas){
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
    if (IDUtas <1){
        printf("Kamu tidak bisa menyambung Utas dengan id utas %d", IDUtas);
        return;
    }
    if (indeksUtas < 1 ){
        printf("Kamu tidak bisa menyambung Utas dengan indeks %d", indeksUtas);
        return;
    }

    int length = KICAUAN(*app).nEff;
    int i = 0;
    boolean found = false;
    while (!found && i<length ){
        if (ELMT( KICAUAN(*app),i ).IDUtas == IDUtas)
        {
            found = true;
        }
        i++;
    }

    if (!found){
        printf("Tidak ditemukan Utas dengan ID Utas %d\n", IDUtas);
        return;
    }
    i--;
    if (LOGINID(*app) != ELMT(KICAUAN(*app), i ).IDuser ){
        printf("Kamu hanya bisa menambahkan utas milikmu sendiri\n");
        return;
    }
    
    if (ELMT( KICAUAN(*app), i).lenUtas < indeksUtas-1){
        printf("Tidak ditemukan indeks Utas dengan indeks %d\n ", indeksUtas);
        return;
    }

    String teks;
    createEmptyString(&teks, 280);
    printf("Masukkan Kicauan: ");
    readString(&teks, 280);
    String namaUser = returnUsername(*app, LOGINID(*app));
    DATETIME formatIntTanggal = currentDateTime ();
    String waktu = DateTimeToString(formatIntTanggal);
    insertAtAnakUtas(&ELMT(KICAUAN(*app), i), indeksUtas, teks, namaUser, waktu);
    printf("Utas berhasil ditambahkan!");
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void display_listUtas(Application *app,int IDUtas){
    if (!LOGGEDIN(*app)) {
        printf("\nAnda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        return;
    }
    if (IDUtas <1){
        printf("Kamu tidak bisa menampilkan Utas dengan id utas %d", IDUtas);
        return;
    }
    int length = KICAUAN(*app).nEff;
    int i = 0;
    boolean found = false;

    while (!found && i<length ){
        if (ELMT( KICAUAN(*app),i ).IDUtas == IDUtas)
        {
            found = true;
        }
        i++;
    }

    if (!found){
        printf("Tidak ditemukan Utas dengan ID Utas %d\n", IDUtas);
        return;
    }
    i--;

    if(LOGINID(*app) != ELMT(KICAUAN(*app), i).IDuser){
        User u = ELMT_LISTUSER(LISTUSER(*app), ELMT(KICAUAN(*app), i).IDuser);
        if (ISPRIVATE(PROFILE(u))){
            if (isFriend (app, LOGINID(*app), ELMT(KICAUAN(*app), i).IDuser)){ 
                printKicauan(ELMT(KICAUAN(*app), i), returnUsername(*app, ELMT(KICAUAN(*app), i).IDuser));
                int j = 0;
                AddressUtas p = FIRST(ELMT(KICAUAN(*app), i));
                while (p != NULL){
                    j ++;
                    printf("\n| INDEX = %d", j);
                    printf("\n| ");
                    displayString(NAMADIUTAS(p));
                    printf("\n| ");
                    displayString(DATETIMEUTAS(p));
                    printf("\n| ");
                    displayString(TEKSDIUTAS(p));
                    printf("\n");
                    p = NEXT_Linked(p);
                }
            } else {
                printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!");
            }
        }
    } else {
        printKicauan(ELMT(KICAUAN(*app), i), returnUsername(*app, ELMT(KICAUAN(*app), i).IDuser));
        int j = 0;
        AddressUtas p = FIRST(ELMT(KICAUAN(*app), i));
        while (p != NULL){
            j ++;
            printf("\n| INDEX = %d", j);
            printf("\n| ");
            displayString(NAMADIUTAS(p));
            printf("\n| ");
            displayString(DATETIMEUTAS(p));
            printf("\n| ");
            displayString(TEKSDIUTAS(p));
            printf("\n");
            p = NEXT_Linked(p);
        }

    }
}

