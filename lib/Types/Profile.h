
#ifndef PROFILE_H
#define PROFILE_H

#include "../boolean.h"
#include "../ADT/String/string.h"
#include "Photo.h"

typedef struct profile {
    String bio;
    String phoneNumber;
    String weton;
    boolean isPrivate;
    Photo photo;
} Profile;


#define BIO(u) (u).bio
#define NOMORHP(u) (u).phoneNumber
#define WETON(u) (u).weton
#define ISPRIVATE(u) (u).isPrivate
#define FOTO(u) (u).photo


void initProfile(Profile *p);
/**
 * I.S.
*/

void readBio(Profile *p, int maxLength);

void readPhoneNumber(Profile *p);

void readWeton(Profile *p);

#endif