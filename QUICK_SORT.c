#include <stdio.h>

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
