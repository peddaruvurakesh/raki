// functions.c
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void d_append(struct dnode **s, int num) {
    struct dnode *temp, *r;
    temp = (struct dnode *)malloc(sizeof(struct dnode));
    temp->data = num;
    temp->next = NULL;
    if (*s == NULL) {
        temp->prev = NULL;
        *s = temp;
    } else {
        r = *s;
        while (r->next != NULL)
            r = r->next;
        r->next = temp;
        temp->prev = r;
    }
}

void d_addatbeg(struct dnode **s, int num) {
    struct dnode *temp;
    temp = (struct dnode *)malloc(sizeof(struct dnode));
    temp->data = num;
    temp->prev = NULL;
    if (*s == NULL) {
        temp->next = NULL;
        *s = temp;
    } else {
        temp->next = *s;
        (*s)->prev = temp;
        *s = temp;
    }
}

void d_addafter(struct dnode *q, int loc, int num) {
    struct dnode *temp;
    int i;

    // Check if the list is empty
    if (q == NULL) {
        printf("The list is empty.\n");
        return;
    }

    // Traverse the list to find the correct position
    for (i = 1; i < loc; i++) {
        q = q->next;
        if (q == NULL) {
            printf("There are fewer than %d elements in the list.\n", loc);
            return;
        }
    }

    // Create the new node
    temp = (struct dnode *)malloc(sizeof(struct dnode));
    temp->data = num;

    // Insert the new node after the q node
    temp->next = q->next;   // Link the new node to the next node
    if (q->next != NULL) {
        q->next->prev = temp;   // Update the next node's previous pointer if it's not NULL
    }
    q->next = temp;   // Link the q node to the new node
    temp->prev = q;   // Set the previous pointer of the new node
}


/*void d_addafter(struct dnode *q, int loc, int num) {
    struct dnode *temp, *r;
    int i;
    temp = (struct dnode *)malloc(sizeof(struct dnode));
    temp->data = num;
    for (i = 0; i < loc; i++) {
        q = q->next;
        if (q == NULL) {
            printf("There are less than %d elements\n", loc);
            return;
        }
    }
    temp->next = q->next;
    if (q->next != NULL)
        q->next->prev = temp;
    q->next = temp;
    temp->prev = q;
}
*/
void d_display(struct dnode *q) {
    if (q == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (q != NULL) {
        printf("%d ", q->data);
        q = q->next;
    }
    printf("\n");
}

int d_count(struct dnode *q) {
    int count = 0;
    while (q != NULL) {
        count++;
        q = q->next;
    }
    return count;
}

void d_delete(struct dnode **s, int num) {
    struct dnode *temp;
    temp = *s;
    while (temp != NULL) {
        if (temp->data == num) {
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                *s = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            free(temp);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found.\n", num);
}

