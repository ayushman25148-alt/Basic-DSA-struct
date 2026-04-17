#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node* next;
};

int search(struct node* Table[], int n, int key){
    int hashValue=key%n;
    struct node* current=Table[hashValue];
    while(current!=NULL){
        if(current->key==key){
            return 1;
        }
        current=current->next;
    }
    return 0;
}

void delete(struct node* Table[], int n, int key){
    if(search(Table,n,key)){
        int hashValue=key%n;
        struct node* current=Table[hashValue];
        struct node* prev=NULL;
        while(current!=NULL){
            if(current->key==key){
                if(prev==NULL){
                    Table[hashValue]=current->next;
                }else{
                    prev->next=current->next;
                }
                free(current);
                break;
            }
            prev=current;
            current=current->next;
        }
    }
}

void insert(struct node* Table[], int n, int key){
    if(!search(Table,n,key)){
        int hashValue=key%n;
        struct node* newNode =(struct node*)malloc(sizeof(struct node));
        newNode->key=key;
        newNode->next=NULL;
        if(Table[hashValue]==NULL){
            Table[hashValue]=newNode;
        }else{
            struct node* current=Table[hashValue];
            while(current->next!=NULL){
                current=current->next;
            }
            current->next=newNode;
        }
    }
}

void insert_at_head(struct node* Table[], int n, int key){
    if(!search(Table,n,key)){
        int hashValue=key%n;
        struct node* newNode =(struct node*)malloc(sizeof(struct node));
        newNode->key=key;
        newNode->next=NULL;
        if(Table[hashValue]==NULL){
            Table[hashValue]=newNode;
        }else{
            newNode->next=Table[hashValue];
            Table[hashValue]=newNode;
        }
    }
}

void printHashTable(struct node* Table[], int n){
    for(int j=0;j<n;j++){
        printf("Index %d: ",j);
        struct node* current=Table[j];
        while(current!=NULL){
            printf("%d ->",current->key);
            current=current->next;
        }
        printf("NULL\n");
    }
}
