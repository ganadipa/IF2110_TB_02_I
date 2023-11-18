#include "Devtools.h"
#include <stdio.h>


void DevTools(Application app) 
{
    printf("\nisLoggedIn : ");
    if (LOGGEDIN(app)) {
        printf("TRUE");
        printf("\nLogged in as ");
        displayName(LISTUSER(app), LOGINID(app));
        printf("  (ID : %d)\n", LOGINID(app));
    }
    else printf("FALSE");

    printf("\n\nGraph pertemanan: \n");
    printGraph(FRIENDSHIPS(app));


    printf("\n\nisi ListUser:\n\n");
    int i;
    for (i = 0; i < LENGTH_LISTUSER(LISTUSER(app)); i++) 
    {
        printf("ID : %d\n", i);
        printf("IS PRIVATE: %d\n", ISPRIVATE(PROFILE(ELMT_LISTUSER(LISTUSER(app), i))));
        displayProfile(ELMT_LISTUSER(LISTUSER(app), i));
        displayPhoto(FOTO(PROFILE(ELMT_LISTUSER(LISTUSER(app), i))));
        printf("\n\n");
    }

    for (int i = 0; i < KICAUAN(app).nEff; i++) {

        printAllReplyTree(BALASAN(KICAUAN(app).buffer[0]));
    }

    
}