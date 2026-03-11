#include <stdio.h>

struct node {
    int key;
    struct node* next;
    struct node* prev;
};

struct list {
    struct node* head;
};

struct node* list_search(struct list* L, int k){
    struct node* x = L->head;
    while(x != 0 && x->key != k){
        x = x->next;
    }
    return x; 
}

void list_prepend(struct list* L, struct node* x){
    x->prev= NULL;
    if(L->head == 0){
        x->next = 0;
    }else{
        x->next = L->head;
        L->head->prev=x;
    }
    L->head = x;
}

void list_insert_after(struct node* y, struct node* x){
    if (y == 0) {
        return;
    }
    x->next = y->next;
    if(y->next!=0){
        y->next->prev= x;
    }
    x->prev=y;
    y->next = x;
}

void list_delete(struct list* L, struct node* x){
    if(x==0){
        return;
    }
    if(x->prev==0){
        L->head = x->next;
    }else{
        x->prev->next = x->next;
    }
    if(x->next != 0){
        x->next->prev=x->prev;
    }
}
