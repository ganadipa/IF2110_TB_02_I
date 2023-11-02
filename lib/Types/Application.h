
#ifndef APPLICATION_H
#define APPLICATION_H

#include "../boolean.h"
#include "./ListUser.h"
#include "../ADT/Graf/graf.h"
#include "listKicauan.h"
#include "DrafKicauan.h"



typedef struct application {
    boolean isLoggedIn;
    int loginID;
    ListUser users; // Used list dengan array statik
    Graf friendships;
    ListKicau listKicauan; 
    DrafKicau drafKicau;
} Application;

#define LOGGEDIN(a) (a).isLoggedIn
#define LISTUSER(a) (a).users
#define LOGINID(a) (a).loginID
#define FRIENDSHIPS(a) (a).friendships
#define KICAUAN(a)  (a).listKicauan
#define DRAFKICAU(a) (a).drafKicau

void AppInitialization(Application *app);
/**
 * I.S. Program baru dimulai.
 * F.S. Output UI CLI dan menampung data-data yang ada pada config yang telah dimasukkan.
*/

void Daftar(Application *app);
/**
 * I.S. app sudah terinisialisasi.
 * F.S. Menambahkan user ke dalam database.
*/


void Masuk(Application *app);
/**
 * I.S. app sudah terinisialisasi
 * F.S. app memasuki mode loggedIn.
*/

void Keluar(Application *app);
/**
 * I.S. app sudah terinisialisasi
 * F.S. app memasuki mode tak loggedIn.
*/

void TutupProgram(Application *app, boolean *finish);
/**
 * I.S. app sudah terinisialisasi
 * F.S. program ditutup tanpa menyimpan apapun dari app.
*/

void GantiProfil(Application *app);
/**
 * I.S. app suadah terinisialisasi, isLoggedIn belum tentu true;
 * F.S. Profil dari id "loginID" diperbarui
*/

void LihatProfil(Application *app, String name);
/**
 * I.S. app sudah terinisialisasi. isLoggedIn belum tentu true;
 * F.S. Menampilkan full profile dari name.
*/
void AturJenisAkun(Application *app);
/**
 * I.S. app sudah terinisialisasi. IsLoggedIn belum tentu true
 * F.S. Mengubah isPrivate User dengan ID == loginID sesuai input.
*/

void DaftarTeman(Application app);
/**
 * 
*/

void UbahFotoProfil(Application *app);
/**
 * 
*/

void HapusTeman(Application *app);

boolean isFriend(Application *app, int ID_yang_ingin_dicek, int friendID);
/**
 * Untuk Mengecek apakah ID yang ingin dicek berteman dengan id friend satu lagi
*/

void Kicau(Application *app);
/**
 * Untuk Add kicauan
*/

void TampilinKicauan(Application *app);
/**
 * Untuk Menampilkan kicauan berdasarkan Pertemanan dari user
*/

void SukaKicauan(Application *app, int ID);
/**
 * Untuk Menambah jumlah like pada Kicauan dengan id "ID"
*/

void UbahKicauan(Application *app, int ID);
/**
 * Untuk mengUpdate teks kicauan menjadi yang baru pada Kicauan dengan id "ID"
*/

void BuatDraf(Application *app); 
/* membuat draf baru untuk Draf kicauan*/
void SimpanDraf(Application *app, Kicauan kicau);
/*Menyimpan draf ke dalam stack*/
void HapusDraf(Application *app, Kicauan *sampahKicau); 
/*Menghapus draf cuitan dari stack*/
void TerbitkanDraf(Application *app, Kicauan kicau, int IDuser); 
/*menerbitkan draf menjadi cuitan*/
void LihatDraf(Application *app); 
/*Melihat draf paling terakhir dari stack*/
void UbahDraf(Application *app, Kicauan temp);
/*Mengubah draf dari paling terakhir*/

void DevTools(Application app);
/**
 * JANGAN LUPA DIAPUS
*/

#endif