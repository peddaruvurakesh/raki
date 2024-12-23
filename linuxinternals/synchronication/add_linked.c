void add_linked_list(linked_list *ll, void* elem) {
    node* packaged = new_node(elem);
    // Critical section starts here
    pthread_mutex_lock(&ll->lock); 
    if (ll->head) {
        packaged->next = ll->head;
    }
    ll->head = packaged;
    ll->size++;
    pthread_mutex_unlock(&ll->lock); 
    // Critical section ends here
}

