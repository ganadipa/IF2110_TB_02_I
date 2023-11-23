#include <stdio.h>
#include "Profile.h"

void initProfile(Profile *p)
/**
 * I.S.
*/
{
    initializePhoto(&FOTO(*p));
    createEmptyString(&BIO(*p), 350);
    createEmptyString(&NOMORHP(*p), 350);
    createEmptyString(&WETON(*p), 350);
    ISPRIVATE(*p) = false;
}

void readBio (Profile *p, int maxLength)
/**
 * I.S. BIO(*p) terdefinisi, p sudah terinisialisasi.
 * F.S. CurrentChar_WordMachine bernilai '\n'
 *      BIO(*p) diperbarui jika panjang masukan <= 135 karakter.
 * 
*/
{
    String bio;
    readString(&bio, 350);

    while (stringLength(bio) > maxLength) {
        printf("\nOops, panjang maksimum bio adalah 135 karakter. Gagal menyimpan bio.\n");
        
    }
    BIO(*p) = bio;
    
}

void readPhoneNumber(Profile *p)

{
    String phoneNumber;
    readString(&phoneNumber, 350);

    if (stringLength(phoneNumber) > 15) {
        printf("Panjang nomor hape tidak boleh melebihi 15 karakter. Gagal menginput nomor hp.");
        return;
    }

    while (!isAllNumber(phoneNumber)) {
        printf("\nNo HP tidak valid. Masukkan lagi yuk!\n");
        printf("\nMasukkan No HP:");
        readString(&phoneNumber, 350);
    }

    NOMORHP(*p) = phoneNumber;
    
}

void readWeton(Profile *p)

{
    String weton;
    readString(&weton, 10);
    

    while 
    (!compareStringInsensitively(weton, "Pahing") 
    && !compareStringInsensitively(weton, "Kliwon") 
    && !compareStringInsensitively(weton, "Wage") 
    && !compareStringInsensitively(weton, "Pon") 
    && !compareStringInsensitively(weton, "Legi") 
    && !compareStringInsensitively(weton, "")) 
    
    {
        printf("\nWeton Anda tidak valid. Ulangi.\n");
        printf("\nMasukkan Weton: \n");
        readString(&weton, 10);
    }
    toTitleCase(&weton);
    WETON(*p) = weton;
}
