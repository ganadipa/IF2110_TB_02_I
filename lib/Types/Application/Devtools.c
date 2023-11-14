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

    // printf("%d", app.listKicauan.buffer[1].IDKicau);
    // printf("\n");
    // displayString(app.listKicauan.buffer[1].text);
    // printf("\n");
    // printf("%d\n", app.listKicauan.buffer[1].like);
    // // printKicauan(app.listKicauan.buffer[0], app.listKicauan.buffer);
    // printf("%d", app.listKicauan.buffer[1].IDuser);
    // printf("\n");
    // displayString(app.listKicauan.buffer[1].dateTime);

    // displayString(app.users.contents[0].name);
    // printf("\n");
    // displayString(app.users.contents[0].password);
    // printf("\n");
    // displayString(app.users.contents[0].profile.bio);
    // printf("\n");
    // displayString(app.users.contents[0].profile.phoneNumber);
    // printf("\n");
    // displayString(app.users.contents[0].profile.weton);
    // printf("\n");
    // readPhoto(&app.users.contents[0].profile.photo);
    // printf("\n");
    // displayPhoto(app.users.contents[0].profile.photo);

    // printf("%x", app.listKicauan.buffer[1].link->next->next->next);
    displayString(app.listKicauan.buffer[1].link->next->next->teks);
    
}