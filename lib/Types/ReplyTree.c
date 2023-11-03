#include <stdio.h>
#include <stdlib.h>
#include "ReplyTree.h"

ReplyAddress newReply(String body, boolean isMain)
/*Membuat balasan dengan id null, authorid null, body terset, dan datetime juga terset*/
{
    ReplyAddress ra = (ReplyAddress) malloc(sizeof(Reply));
    REPLYID(*ra) = ID_UNDEF;
    BODY(*ra) = body;
    AUTHORID(*ra) = ID_UNDEF;
    DTIME(*ra) = currentDateTime();
    ISMAIN(*ra) = isMain;

    return ra;
}

void createReplyTree(ReplyTree *rt, int capacity)

{
    rt -> adjlists = (ListDin *) malloc(sizeof(ListDin));
    rt -> listreply->buffer = (ReplyAddress *) malloc(sizeof(ReplyAddress)*capacity);
    USED(*rt).buffer = (int *) malloc(sizeof(int)*capacity);
    NUMREP(*rt) = 0;
    MAXREP(*rt) = 0;
    rt -> availableID = 0;
    rt -> availableIDX = 0;
}

void extendReplyTree(ReplyTree *rt) 
/**
 * I.S. Compressed rt.
*/
{
    ReplyTree tmp;
    createReplyTree(&tmp, 2*(rt -> maxReply));

    tmp.numReplyEff = rt -> numReplyEff;
    tmp.availableID = rt -> availableID;
    tmp.availableIDX = rt -> availableIDX;
    tmp.maxReply = rt -> maxReply;
    LISTREP(tmp).neff = LISTREP(*rt).neff;

    int len = tmp.numReplyEff;
    int i;
    for (i = 0; i < len; i++) {
        LISTDIN(tmp, i) = LISTDIN(*rt, i);
        ADDR(LISTREP(tmp), i) = ADDR(LISTREP(*rt), i);
        ISUSED(tmp, i) = ISUSED(*rt, i);
    }

    *rt = tmp;
}

void compressReplyTree(ReplyTree *rt)
// jadiin rata kiri
{
    int i, j;
    for (i = 0; i < rt -> availableID; i++ )
    {
        if (ISUSED(*rt, i)) continue;

        for (j = i+1; j < rt -> availableID; j++)
        {
            if (ISUSED(*rt, j) > ISUSED(*rt, i))
            {
                swapIndexTree(rt, i , j);
                break;
            }
        }
    }

    rt -> availableIDX = rt -> numReplyEff;
}

int getIdxInReplyTree(ReplyTree rt, ReplyAddress addr)
{
    int i;
    int len = rt.maxReply;
    for (i= 0; i < len; i++) {
        if (ADDR(LISTREP(rt), i) == addr) break;
    }

    return i;
}

void swapIndexTree(ReplyTree *rt, int i, int j)

{
    // Swaping the adjlists
    ListDin tmpld;
    tmpld =LISTDIN(*rt, i);
    LISTDIN(*rt, i) = LISTDIN(*rt, j);
    LISTDIN(*rt, j) = tmpld;

    // swap elmt inside list reply
    ReplyAddress tmpra;
    tmpra = ADDR(LISTREP(*rt), i);
    ADDR(LISTREP(*rt), i) = ADDR(LISTREP(*rt), j);
    ADDR(LISTREP(*rt), j) = tmpra;

    // swap elmt inside list used.
    int tmpi;
    tmpi = ((USED(*rt)).buffer[i]);
    ((USED(*rt)).buffer[i]) = ((USED(*rt)).buffer[j]);
    ((USED(*rt)).buffer[j]) = tmpi;
  
}

int generateReplyID(ReplyTree rt) {
    return rt.availableID;
}

void addReply(ReplyTree *rt)
{
    if (rt -> availableIDX == rt -> maxReply)
    {
        compressReplyTree(rt);
    }

    NUMREP(*rt) += 1;
    rt -> availableID += 1;
    rt -> availableIDX += 1;
}

void addChildToReply(ReplyTree *rt, ReplyAddress parent, ReplyAddress child)
/**
 * I.S. replyadrress dari parent dan child terdefinisi.
*/
{
    int idxParent = getIdxInReplyTree(*rt, parent);
    int idxChild = getIdxInReplyTree(*rt, child);

    insertLastListDin(&LISTDIN(*rt, idxParent), idxChild);
}


void printSpace(int num) {
    while (num > 0){
        printf(" ");
        num--;
    }
}

void displayReply(ReplyAddress addr, ListUser l, int depth)

{
    Reply rep = *addr;

    printSpace(depth);
    printf(" | ID = %d\n", REPLYID(rep));

    User u = ELMT_LISTUSER(l, AUTHORID(rep));
    boolean public = !ISPRIVATE(PROFILE(u));

    if (!public) {
        printSpace(depth);
        printf(" | PRIVAT\n");

        printSpace(depth);
        printf(" | PRIVAT\n");
        
        printSpace(depth);
        printf(" | PRIVAT\n");

    } else {
        String authorName = NAME(u);

        printSpace(depth);
        printf(" | ");
        displayString(authorName);
        printf("\n");

        printSpace(depth);
        printf(" | ");
        displayString(DateTimeToString(DTIME(rep)));
        printf("\n");

        printSpace(depth);
        printf(" | ");
        displayString(BODY(rep));
        printf("\n");
    }
}

void displayAllReply(ReplyTree rt, ListUser l)
// I.S. compressed rt
{
    int length = rt.numReplyEff;
    int i;
    for (i = 0; i < length; i++) {
        Reply r = (*ADDR(LISTREP(rt), i));
        if (ISMAIN(r)) {
            displayAllReply_helper(rt, l, 0, i);
        }
    }
}

void displayAllReply_helper(ReplyTree rt, ListUser l, int currDepth, int idx)
{
    ListDin adjlist = LISTDIN(rt, idx);
    ReplyAddress ra = ADDR(LISTREP(rt), idx);
    int neff = NEFF(adjlist);
    int i;
    displayReply(ra, l, currDepth);
    for (i = 0; i < neff; i++) {
        displayAllReply_helper(rt, l, currDepth+1, adjlist.buffer[i]);
    }
}