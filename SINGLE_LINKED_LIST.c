#include <stdio.h>

struct nodell{
    int key;
    struct nodell* next;
};

struct linkedlist{
    struct nodell* head;    
};

struct nodell* list_search(struct linkedlist* l,int k){
    struct nodell* x = l->head;
    while(x!=0 && x->key!=k){
        x=x->next;
    }
    return x;
}

void list_prepend(struct linkedlist* l, struct nodell* x){
    if(l->head==0){
        x->next=0;
    }else{
        x->next=l->head;
    }
    l->head=x;
}

void insertion_after(struct nodell* y,struct nodell* x){
    if(y==0){
        return;
    }
    x->next=y->next;
    y->next=x;
}

void ll_deletion(struct linkedlist* l,struct nodell* prev,struct nodell* x){
    if(x==0){
        return;
    }
    if (prev==0){
        l->head=x->next;
    }else{
        prev->next = x->next;
    }
}
