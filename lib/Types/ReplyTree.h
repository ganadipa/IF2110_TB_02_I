// #ifndef replyTREE_H
// #define replyTREE_H

// #include "../ADT/ListDinamik/listdinamik.h"
// #include "../ADT/DateTime/datetime.h"

// typedef Reply *ReplyAddress; 

// typedef struct reply {
//     int id;
//     String body;
//     int authorID;
//     DATETIME time;
// } Reply;

// #define REPLYID(r) (r).id
// #define BODY(r) (r).body
// #define AUTHORID(r) (r).authorID
// #define DTIME(r) (r).time

// typedef struct replytree {
//     ListDin *adjlists; // pointer to first list dinamis
//     ListReply *listreply; 
//     ListDin* used;
//     int numReply;
//     int maxReply;
// } ReplyTree;

// #define LISTDIN(rt, i) (rt).adjlists[i]
// #define USED(rt) (rt).used[i]
// #define NUMREP(rt) (rt).numReply
// #define MAXREP(rt) (rt).maxReply


// typedef struct listreply{
//     ReplyAddress *buffer;
//     int neff;
//     int capacity;
// } ListReply;

// #define CAPLR(lr) (lr).capacity
// #define NEFFLR(lr) (lr).neff
// #define ADDR(lr, i) (lr).buffer[i]

// int generateReplyID(ReplyTree *rt);

// void createReplyTree(ReplyTree *rt, int capacity);

// void extendReplyTree(ReplyTree *rt);

// void compressReplyTree(ReplyTree *rt);

// void addReply(ReplyTree *rt);

// void addChildToReply(ReplyTree *rt, ReplyAddress parent, ReplyAddress child);

// void displayReply(ReplyTree *rt, ReplyAddress addr);

// void displayAllReply(ReplyTree *rt, int maxDepth, int maxSibling);




// #endif