#include <stdio.h>
#include <stdlib.h>

void insertionsort(int arr[],int n){
    for(int j=1;j<=n;j++){
        int key = arr[j];
        int i = j-1;
        while(i>=0){
            if(arr[i]>key){
                arr[i+1]=arr[i];
                i--;
            }
        }
        arr[i+1]=key;
    }
}

void merge(int arr[],int p,int q,int r){
    int nl = q-p+1;
    int nr = r-q;
    int left[nl+1];
    int right[nr+1];
    for(int i=0;i<=nl-1;i++){
        left[i]=arr[p+i];
    }
    for(int j=0;j<=nr-1;j++){
        right[j] =arr[q+1+j];
    }
    left[nl]=10000;
    right[nr]=10000;
    int a=0;
    int b=0;
    for(int k = p;k<=r;k++){
        if(left[a]>right[b]){
            arr[k]=left[a];
            a++;
        }else{
            arr[k]=right[b];
            b++;
        }
    }
}

void mergesort(int arr[],int p,int r){
    while(p<r){
        int q = (p+r)/2;
        mergesort(arr,p,q);
        mergesort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}

void selectionsort(int arr[],int n){
    for(int i=0;i<=n-2;i++){
        int min = i;
        for(int j=i+1;j<=n-1;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void bubblesort(int arr[],int n){
    for(int i=0;i<=n-2;i++){
        for(int j=n-1;j<i+1;j--){
            if(arr[j]<arr[j-1]){
                int temp = arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
}

int partionquicksort(int arr[],int p, int q){
    int key = arr[p];
    int i = p;
    for(int j=p+1;j<=q;j++){
        if(arr[j]<= key){
            i++;
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;  
        }
    }
    int tempt = arr[p];
    arr[p] = arr[i];
    arr[i] = tempt;
    return i;
}

void quicksort(int arr[],int p,int r){
    if(p<r){
        int q = partionquicksort(arr,p,r);
        quicksort(arr,p,q);
        quicksort(arr,q+1,r);
        //Give intial call of quicksort(arr,0,n-1) 
    }
}

//Single linked list

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

//Double linked list
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

//Stack
void stack_push(int* s ,int* top,int n, int ele){
    if(*top == n-1){
        printf(" Overflow : Stack is full !\n");
        return;
    }
    (*top)++;
    s[*top] = ele;
}

int stack_pop(int* s,int* top){
    if (*top == -1){
        printf(" Underflow : Stack is empty !\n");
        return 0;
    }
    (*top)--;
    return s[*top+1];
}

void print_stack(int*s ,int*top){
    int i;
    for(int i=0;i<* top ;i++){
        printf("%d ", s[i]);
    }
    printf(" <-top \n\n");
}

//Queue
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