#ifndef KICAUAN_H
#define KICAUAN_H
#include "../boolean.h"
#include "../ADT/String/string.h" 
#include "../ADT/DateTime/datetime.h"  
#include "ReplyTree.h"
#include "listUtas.h"


typedef struct {
    int IDKicau;        // ID Kicau
    int IDuser;         // ID User yang melakukan kicau ini
    String dateTime;    // Menyimpan dateTime Kicauan
    String text;        // Menyimpan teks Kicauan
    int like;           // Menyimpan jumlah like 
    ReplyTree balasan;  // Graph Balasan
    int IDUtas;         // Menyimpan ID Utas untuk tiap kicauan 
    AddressUtas link;   // Menyimpan link untuk pergi ke linked list utas
    int lenUtas;        // Menyimpan jumlah utas dari tiap kicau
} Kicauan;

#define IDKicau(u) (u).IDKicau
#define userKicau(u) (u).IDuser
#define dateTimeKicau(u) (u).dateTime
#define teksKicau(u) (u).text
#define likeKicau(u) (u).like
#define BALASAN(u) (u).balasan
#define IDUTAS(u) (u).IDUtas
#define FIRST(u) (u).link //ke Utas dengan index pertama 1
#define LEN_ANAKUTAS(u) (u).lenUtas

#define TABLE_SIZE 1000 // Ukuran Hashmap

typedef struct {
    String tagar;
    Kicauan *kicauan;
    int isOccupied;
} HashNode;

#define GET_TAGAR(node) ((node).tagar)
#define GET_KICAUAN(node) ((node).kicauan)
#define IS_OCCUPIED(node) ((node).isOccupied)


typedef HashNode HashTable[TABLE_SIZE];

unsigned long long int hashFunction(String tagar);

void inisialisasiHashTable( HashTable  *table);

void insertKicauankeTable(HashTable *table, String tagar, Kicauan *kicauan);



void InisialisasiKicau(Kicauan *k, int IDuser);
/**
 * I.S. u sembarang
 * F.S. user memiliki name "user" dan ID "ID", dan properti sisanya default.
*/

void  nambahlenUtas(Kicauan *k);

void  kuranglenUtas(Kicauan *k);

void insertAtAnakUtas(Kicauan *k  ,int indeksUtas,String teks,String namaUser, String time);
// Menambah utas sesuai dengan indeks utas

void deleteAtAnakUtas (Kicauan *k ,int indeksUtas, String *teks, String *namaUser, String *time);
// Menghapus utas sesuai dengan indeks utas

void setKicauID(Kicauan *k, int ID);
/**
 * I.S. k sudah diinisilisasi
 * F.S. Mengeset id menjadi id sekarang
*/

void setKicauDateTime(Kicauan *k);
/**
 * I.S. k sudah diinisilisasi
 * F.S. Mengeset dateTime menjadi datetime sekarang
*/
void setText(Kicauan *k, String teks);
/**
 * I.S. k sudah diinisilisasi
 * F.S. Mengeset text menjadi text terbaru
*/

void addLike(Kicauan *k);
/**
 * I.S. k sudah diinisilisasi
 * F.S. Mengincrement like 
*/

void printKicauan(Kicauan k, String nama);
/**
 * Print Kicauan 
*/



#endif