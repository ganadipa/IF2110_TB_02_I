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
        printf("ID : %d", i);
        displayProfile(ELMT_LISTUSER(LISTUSER(app), i));
        displayPhoto(FOTO(PROFILE(ELMT_LISTUSER(LISTUSER(app), i))));
        printf("\n\n");
    }

    // for (int i = 0; i < KICAUAN(app).nEff; i++) {

    //     printAllReplyTree(BALASAN(KICAUAN(app).buffer[0]));
    // }

    // printf("%d", app.listKicauan.buffer[0].IDKicau);
    // printf("\n");
    // displayString(app.listKicauan.buffer[0].text);
    // printf("\n");
    // // printKicauan(app.listKicauan.buffer[0], nama);
    // printf("%d", app.listKicauan.buffer[0].IDuser);
    // printf("\n");
    // displayString(app.listKicauan.buffer[0].dateTime);

    displayString(app.users.contents[0].name);
    printf("\n");
    displayString(app.users.contents[0].password);
    printf("\n");
    displayString(app.users.contents[0].profile.bio);
    printf("\n");
    displayString(app.users.contents[0].profile.phoneNumber);
    printf("\n");
    displayString(app.users.contents[0].profile.weton);
    printf("\n");
    readPhoto(&app.users.contents[0].profile.photo);
    printf("\n");
    displayPhoto(app.users.contents[0].profile.photo);
    
}