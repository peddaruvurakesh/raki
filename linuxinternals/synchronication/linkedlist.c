#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL; // Shared resource
pthread_mutex_t lock;

void* add_to_list(void* arg) {
    int value = *(int*)arg;
    pthread_mutex_lock(&lock);

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = head;
    head = new_node;

    pthread_mutex_unlock(&lock);
    return NULL;
}

void print_list() {
    pthread_mutex_lock(&lock);

    Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    pthread_mutex_unlock(&lock);
}

int main() {
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL);

    int val1 = 10, val2 = 20, val3 = 30, val4 = 40;

    pthread_create(&t1, NULL, add_to_list, &val1);
    pthread_create(&t2, NULL, add_to_list, &val2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_create(&t1, NULL, add_to_list, &val3);
    pthread_create(&t2, NULL, add_to_list, &val4);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    print_list();

    pthread_mutex_destroy(&lock);
    return 0;
}

