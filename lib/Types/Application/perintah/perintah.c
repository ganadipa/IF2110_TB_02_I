#include <stdio.h>
#include "perintah.h"

void handleCommand(Application* app, String command, boolean *finish) 
/**
 * 
*/
{
    int numword = countWord(command);
    if (numword == 0) return;


    String firstWord = getWordAt(command, 0);
    String secondWord;
    String thirdWord;


    if (numword >= 1) secondWord = getWordAt(command, 1);
    if (numword >= 2) thirdWord = getWordAt(command, 2);


    if (compareString(firstWord, "DAFTAR")){
        Daftar(app);
    } else if (compareString(firstWord, "MASUK")) {
        Masuk(app);
    } else if (compareString(firstWord, "KELUAR")) {
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
        LihatProfil(app, secondWord);
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
    } else if (compareString(firstWord, "KICAUAN")) {
        TampilinKicauan(app);
    } else if (compareString(firstWord, "SUKA_KICAUAN")) {
        int ID = stringToInt(secondWord);
        SukaKicauan(app,ID);
    } else if (compareString(firstWord, "UBAH_KICAUAN")) {
        int ID = stringToInt(secondWord);
        UbahKicauan(app,1);
    } else if (compareString(firstWord, "TAMBAH_TEMAN")) {
        TambahTeman(app);
    } else if (compareString(firstWord, "BATAL_TAMBAH_TEMAN")) {
        BatalTambahTeman(app);
    } else if (compareString(firstWord, "DAFTAR_PERMINTAAN_PERTEMANAN")) {
        DaftarPermintaanPertemanan(*app);
    } else if (compareString(firstWord, "SETUJUI_PERTEMANAN")) {
        SetujuiPertemanan(app);
    }


    else {
        printf("\nTidak ada perintah ");
        displayString(command);
        printf(". Baca dokumentasi (Spesifikasi) untuk melihat seluruh perintah.\n");  
    }

}

