#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Function to add a new node at the end of the doubly linked list
void d_append(struct dnode **s, int num) {
    struct dnode *new_node = (struct dnode *)malloc(sizeof(struct dnode));
    new_node->data = num;
    new_node->next = NULL;

    if (*s == NULL) {
        new_node->prev = NULL;
        *s = new_node;
    } else {
        struct dnode *temp = *s;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

// Function to add a new node at the beginning of the doubly linked list
void d_addatbeg(struct dnode **s, int num) {
    struct dnode *new_node = (struct dnode *)malloc(sizeof(struct dnode));
    new_node->data = num;
    new_node->prev = NULL;

    if (*s == NULL) {
        new_node->next = NULL;
        *s = new_node;
    } else {
        new_node->next = *s;
        (*s)->prev = new_node;
        *s = new_node;
    }
}

// Function to add a new node after the specified number of nodes
/*void d_addafter(struct dnode *q, int pos, int num) {
    struct dnode *temp = q;
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp != NULL) {
        struct dnode *new_node = (struct dnode *)malloc(sizeof(struct dnode));
        new_node->data = num;
        new_node->next = temp->next;
        new_node->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = new_node;
        }
        temp->next = new_node;
    } else {
        printf("Location out of bounds\n");
    }
}*/
void d_addafter(struct dnode *q, int pos, int num) {
    struct dnode *temp = q;

    // Special case for adding at position 0 (before the first node)
    if (pos == 0) {
        struct dnode *new_node = (struct dnode *)malloc(sizeof(struct dnode));
        new_node->data = num;
        new_node->next = temp;  // Set the new node's next to the current head
        new_node->prev = NULL;  // The new node becomes the head, so prev is NULL

        if (temp != NULL) {  // If there's already a head, set the previous pointer of the old head to the new node
            temp->prev = new_node;
        }
        q = new_node;  // Update the head of the list to the new node
        return;  // Exit after inserting at the beginning
    }

    // Regular case for adding after a given position
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp != NULL) {
        struct dnode *new_node = (struct dnode *)malloc(sizeof(struct dnode));
        new_node->data = num;
        new_node->next = temp->next;
        new_node->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = new_node;
        }
        temp->next = new_node;
    } else {
        printf("Location out of bounds\n");
    }
}


// Function to display the contents of the doubly linked list
void d_display(struct dnode *q) {
    struct dnode *temp = q;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to count the number of nodes in the doubly linked list
int d_count(struct dnode *q) {
    int count = 0;
    struct dnode *temp = q;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to delete the specified node from the doubly linked list
void d_delete(struct dnode **s, int num) {
    struct dnode *temp = *s;
    while (temp != NULL && temp->data != num) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found\n", num);
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *s = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

