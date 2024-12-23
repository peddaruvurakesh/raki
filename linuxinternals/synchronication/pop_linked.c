void* pop_elem(linked_list *ll, size_t index) {
    if (index >= ll->size) return NULL;

    node *i, *prev = NULL;

    pthread_mutex_lock(&ll->lock); // Critical section starts
    for (i = ll->head; i && index; i = i->next, index--) {
        prev = i;
    }

    if (prev && prev->next) prev->next = i->next;
    else if (i == ll->head) ll->head = i->next;

    ll->size--;
    void* elem = i->elem;
    pthread_mutex_unlock(&ll->lock); // Critical section ends

    destroy_node(i);
    return elem;
}

