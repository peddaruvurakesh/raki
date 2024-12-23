#ifndef HEADER_H
#define HEADER_H

// Structure representing a node of the doubly linked list
struct dnode {
    struct dnode *prev;
    int data;
    struct dnode *next;
};

// Function prototypes
void d_append(struct dnode **s, int num);
void d_addatbeg(struct dnode **s, int num);
void d_addafter(struct dnode *q, int loc, int num);
void d_display(struct dnode *q);
int d_count(struct dnode *q);
void d_delete(struct dnode **s, int num);

#endif

