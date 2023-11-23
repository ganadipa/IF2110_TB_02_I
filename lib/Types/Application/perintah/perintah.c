#include <stdio.h>
#include "perintah.h"

void handleCommand(Application* app, String command, boolean *finish) 
/**
 * 
*/
{
    int numword = countWord(command);
    if (numword == 0) return;

    String firstWord;
    String rest;
    SplitIntoTwo(command, &firstWord, &rest);


    String secondWord;
    String thirdWord;


    if (numword >= 1) secondWord = getWordAt(command, 1);
    if (numword >= 2) thirdWord = getWordAt(command, 2);


    if (compareString(firstWord, "DAFTAR")){
        Daftar(app);
    } else if (compareString(firstWord, "MASUK")){
        Masuk(app);
    } else if (compareString(firstWord, "KELUAR")){
        Keluar(app);
    } else if (compareString(firstWord, "DEVTOOLS")) {
        /**
         * Command Developer Tools akan dihilangkan saat pengumpulan, ini hanya alat untuk debugging.
        */
        DevTools(*app);
    } else if (compareString(firstWord, "TUTUP_PROGRAM")) {
        TutupProgram(app, finish);
    } else if (compareString(firstWord, "GANTI_PROFIL")) {
        GantiProfil(app);
    } else if (compareString(firstWord, "LIHAT_PROFIL")) {
        if (numword < 2) {
            printf("\nPerintah yang valid: \"LIHAT_PROFIL <nama> ;\".\n");
            return;
        }
        LihatProfil(app, rest);
    } else if (compareString(firstWord, "ATUR_JENIS_AKUN")) {
        AturJenisAkun(app);
    } else if (compareString(firstWord, "UBAH_FOTO_PROFIL")) {
        UbahFotoProfil(app);
    } else if (compareString(firstWord, "DAFTAR_TEMAN")) {
        DaftarTeman(*app);
    } else if (compareString(firstWord, "HAPUS_TEMAN")) {
        HapusTeman(app);
    } else if (compareString(firstWord, "KICAU")) {
        Kicau(app);
        // displayString((*app).hashMap[63].tagar);
        // String namaa = {"GANA", 20};
    // printKicauan(*(*app).hashMap[63].kicauan, namaa);
    } else if (compareString(firstWord, "CARI_KICAUAN")) {
    //     displayString((*app).hashMap[63].tagar);
    //     String namaa = {"GANA", 20};
    // printKicauan(*(*app).hashMap[63].kicauan, namaa);
        cariKicauanDenganTagar(app, secondWord);
    } else if (compareString(firstWord, "KICAUAN")) {
        TampilinKicauan(app);
    } else if (compareString(firstWord, "SUKA_KICAUAN")) {
        if (numword != 2) {
            printf("\nPerintah yang valid: \"SUKA_KICAUAN <IDKicau>;\".\n");
            return;
        }
        int ID = stringToInt(secondWord);
        SukaKicauan(app,ID);
    } else if(compareString(firstWord, "BUAT_DRAF")){
        CreateDraf(app);
    } else if(compareString(firstWord, "LIHAT_DRAF")){
        DisplayDraf(app);
    }else if (compareString(firstWord, "UBAH_KICAUAN")) {
        if (numword != 2) {
            printf("\nPerintah yang valid: \"UBAH_KICAUAN <IDKicau>;\".\n");
            return;
        }
        int ID = stringToInt(secondWord);
        UbahKicauan(app,ID);
    } else if (compareString(firstWord, "TAMBAH_TEMAN")) {
        TambahTeman(app);
    } 
    // else if (compareString(firstWord, "BATAL_TAMBAH_TEMAN")) {
    //     BatalTambahTeman(app);
    // } 
    else if (compareString(firstWord, "DAFTAR_PERMINTAAN_PERTEMANAN")) {
        DaftarPermintaanPertemanan(*app);
    } else if (compareString(firstWord, "SETUJUI_PERTEMANAN")) {
        SetujuiPertemanan(app);
    } else if (compareString(firstWord, "BALAS")) {
        if (numword != 3) {
            printf("\nPerintah yang valid: BALAS \"<IDKicau> <IDBalasan>;\".\n");
            return;
        }
        int IDKicau = stringToInt(secondWord);
        int IDBalasan = stringToInt(thirdWord);
        Balas(app, IDKicau, IDBalasan);
    } else if (compareString(firstWord, "BALASAN")) {
        if (numword != 2) {
            printf("\nPerintah yang valid: \"BALASAN <IDKicau>;\".\n");
            return;
        }
        int IDKicau = stringToInt(secondWord);
        Balasan(app, IDKicau);
    } else if (compareString(firstWord, "HAPUS_BALASAN")) {
        if (numword != 3) {
            printf("\nPerintah yang valid: \"HAPUS_BALASAN <IDKicau> <IDBalasan>;\".\n");
            return;
        }
        int IDKicau = stringToInt(secondWord);
        int IDBalasan = stringToInt(thirdWord);
        HapusBalasan(app, IDKicau, IDBalasan);
    } else if(compareString(firstWord, "SIMPAN")){
        SaveFolder(app);
    } else if ( compareString(firstWord , "UTAS")){
        if (numword != 2) {
            printf("\nPerintah yang valid: \"UTAS <IDKICAU>;\".\n");
            return;
        }
        int IDKicau = stringToInt(secondWord);
        insertUtas_withIDKicau(app, IDKicau);
    } else if ( compareString(firstWord , "SAMBUNG_UTAS")){
        if (numword != 3) {
            printf("\nPerintah yang valid: \"SAMBUNG_UTAS <IDUTAS> <INDEKSUTAS>;\".\n");
            return;
        }
        int IDutas = stringToInt(secondWord);
        int index = stringToInt(thirdWord);
        NyambungAnakUtas(app, IDutas, index);  
    } else if ( compareString(firstWord , "HAPUS_UTAS")){
        if (numword != 3) {
            printf("\nPerintah yang valid: \"HAPUS_UTAS <IDUTAS> <INDEKSUTAS>;\".\n");
            return;
        }
        int IDutas = stringToInt(secondWord);
        int index = stringToInt(thirdWord);
        deleteAt_Utas(app, IDutas, index);
    }else if ( compareString(firstWord , "CETAK_UTAS")){
        if (numword != 2) {
            printf("\nPerintah yang valid: \"CETAK_UTAS <IDUTAS>;\".\n");
            return;
        }
        int IDutas = stringToInt(secondWord);
        display_listUtas(app, IDutas);
    } else if(compareString(firstWord , "MUAT")){
        String pathfilefolder;
        if(app->isLoggedIn){
            printf("Anda harus keluar terlebih dahulu untuk melakukan pemuatan.\n");
        }
        else{
            printf("Masukkan nama folder yang hendak dimuat.\n");
            readString(&pathfilefolder, 351);
            *app = MuatFolder(app, pathfilefolder);
        }
    }
    else {
        printf("\nTidak ada perintah ");
        displayString(command);
        printf(". Baca dokumentasi (Spesifikasi) untuk melihat seluruh perintah.\n");  
    }
}

