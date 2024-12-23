#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

// Define linked list structures
typedef struct node {
    void* elem;
    struct node* next;
} node;

typedef struct linked_list {
    node* head;
    size_t size;
    pthread_mutex_t lock;  // Mutex for synchronizing access
} linked_list;

// Function to create a new node
node* new_node(void* elem) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->elem = elem;
    new_node->next = NULL;
    return new_node;
}

// Function to destroy a node
void destroy_node(node* n) {
    free(n);
}

// Add to the linked list
void add_linked_list(linked_list* ll, void* elem) {
    node* packaged = new_node(elem);

    pthread_mutex_lock(&ll->lock);  // Lock the critical section
    if (ll->head) {
        packaged->next = ll->head;  // Add at the head
        ll->head = packaged;
    } else {
        ll->head = packaged;  // Initialize head
    }
    ll->size++;  // Update size
    pthread_mutex_unlock(&ll->lock);  // Unlock the critical section
}

// Pop an element from the linked list
void* pop_elem(linked_list* ll, size_t index) {
    pthread_mutex_lock(&ll->lock);  // Lock the critical section
    if (index >= ll->size) {
        pthread_mutex_unlock(&ll->lock);  // Unlock if invalid index
        return NULL;
    }

    node *i = ll->head, *prev = NULL;
    for (; i && index; i = i->next, index--) {
        prev = i;
    }

    // i now points to the element to be popped
    if (!i) {
        pthread_mutex_unlock(&ll->lock);
        return NULL;  // Index out of bounds
    }

    if (prev) {
        prev->next = i->next;  // Skip the node
    } else {
        ll->head = i->next;  // Update head if popping the first element
    }
    ll->size--;  // Update size

    void* elem = i->elem;
    destroy_node(i);  // Free the node
    pthread_mutex_unlock(&ll->lock);  // Unlock the critical section
    return elem;
}

// Initialize linked list
void init_linked_list(linked_list* ll) {
    ll->head = NULL;
    ll->size = 0;
    pthread_mutex_init(&ll->lock, NULL);  // Initialize mutex
}

// Destroy linked list
void destroy_linked_list(linked_list* ll) {
    pthread_mutex_lock(&ll->lock);
    node* current = ll->head;
    while (current) {
        node* temp = current;
        current = current->next;
        destroy_node(temp);
    }
    pthread_mutex_unlock(&ll->lock);
    pthread_mutex_destroy(&ll->lock);  // Destroy mutex
}

// Example Usage
int main() {
    linked_list ll;
    init_linked_list(&ll);

    int data1 = 10, data2 = 20, data3 = 30;
    add_linked_list(&ll, &data1);
    add_linked_list(&ll, &data2);
    add_linked_list(&ll, &data3);

    printf("Popped element: %d\n", *(int*)pop_elem(&ll, 0));  // Pop the first element
    printf("Popped element: %d\n", *(int*)pop_elem(&ll, 0));  // Pop the next element

    destroy_linked_list(&ll);
    return 0;
}

