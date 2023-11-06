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
    if (LOGINID(*app) == ELMT(KICAUAN(*app), IDKicau - 1).IDuser  ){
        printf("Utas Berhasil Dibuat!\n");
        String teksBaru;
        createEmptyString(&teksBaru, 280);
        printf("Kicauan yang dimasukkan terpotong secara otomatis apabila jumlah karakter lebih dari 280.\n");
        printf("Masukkan Kicauan : ");
        readString(&teksBaru, 280);

        String namaUser = returnUsername(*app, LOGINID(*app));
        
    }else{
        printf("Kamu hanya bisa mengubah kicauan milikmu sendiri\n");
    }
    
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void deleteAt_Utas(Application *app, int IDUtas, int indeksUtas);
//MEnghapus anak Utas berdasarkan ID UTAS, TIDAK BISA MENGHAPUS UTAS PERTAMA

void NyambungUtas(Application *app, int IDUtas, int IndeksUtas);

/****************** PROSES SEMUA ELEMEN LIST ******************/
void display_listUtas(Application *app,int IDUtas);
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
