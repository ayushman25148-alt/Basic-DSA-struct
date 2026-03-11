#include <stdio.h>

void enqueue(int* q,int* head,int* tail,int n,int ele){
    if (*tail == n){
        printf (" Overflow : Queue is full !\n");
        return;
    }
    q[*tail]= ele;
    (*tail )++;
}

int dequeue(int* q,int* head,int* tail,int n){
    int x;
    if (*tail == *head){
        printf(" Underflow : Queue is empty !\n") ;
        return 0;
    }
    x = q[*head];
    (*head)++;
    return x;
}

void print(int* q, int* head,int* tail,int n){
    int i;
    printf("head - > ");
    for(int i=(* head );i<(* tail );i++){
        printf("%d ",q[i]);
    }
    printf(" <-tail \n");
    printf("\n");
}
