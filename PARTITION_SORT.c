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
