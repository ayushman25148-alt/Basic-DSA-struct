#include <stdio.h>

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
