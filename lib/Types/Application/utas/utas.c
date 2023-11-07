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
     if (  ELMT(KICAUAN(*app)  , IDKicau -1).IDUtas != 0 ){
        printf("Kicauan ini sudah menjadi kicauan utama dari utas lain.");
        return;
    }
    if (LOGINID(*app) == ELMT(KICAUAN(*app), IDKicau - 1).IDuser  ){
        printf("Utas Berhasil Dibuat!\n");
        String teksBaru;
        createEmptyString(&teksBaru, 280);
        boolean again = false;
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
            if (again){
                printf("insertwithID"); // INI TINGGAL TUNGGU ADT INSERTATANAKUTAS
            }else{
                FIRST(ELMT(KICAUAN(*app)  , IDKicau -1) ) = NewNode;
                JUMLAHUTAS(*app) = JUMLAHUTAS(*app) + 1;
                LEN_ANAKUTAS(ELMT(KICAUAN(*app), IDKicau - 1)) = LEN_ANAKUTAS(ELMT(KICAUAN(*app), IDKicau - 1)) + 1;
            }
            printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)");
            String lanjutlagi;
            createEmptyString(&teksBaru, 5);
            readString(&lanjutlagi, 5);
            again= compareStringInsensitively(lanjutlagi, "YA");

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
    }
    if (indeksUtas == 0){
        printf("Kamu tidak bisa menghapus kicauan utama");
        return;}
    
    if (ELMT( KICAUAN(*app), i).lenUtas < indeksUtas){
        printf("Tidak ditemukan indeks Utas dengan indeks %d\n ", indeksUtas);
        return;
    }                                        

    // deleteAtAnakUtas( ELMT(KICAUAN(*app), i), indeksUtas);    INI TINGGAL TUNGGU ADT deleteAtAnakUtas
    
    printf("Utas berhasil dihapus!");
}
//MEnghapus anak Utas berdasarkan ID UTAS, TIDAK BISA MENGHAPUS UTAS PERTAMA

void NyambungUtas(Application *app, int IDUtas, int IndeksUtas); //WEGEE

/****************** PROSES SEMUA ELEMEN LIST ******************/
void display_listUtas(Application *app,int IDUtas);  //WEGEE
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
