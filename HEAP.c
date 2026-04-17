#include <stdio.h>

//Heap
int parent(int i){
    return (i-1)/2;
}
int left(int i){
    return 2*i+1;
}
int right(int i){
    return 2*i+2;
}
void max_heapify(int arr[],int n,int i){
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l<=n&&arr[l]>arr[i]){
        largest = l;
    }
    if(r<=n && arr[r]>arr[largest]){
        largest = r;
    }
    if(largest!=i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        max_heapify(arr,n,largest);
    }
}
void build_max_heap(int arr[],int n){
    for(int i=(n-1)/2;i>=0;i--){
        max_heapify(arr,n,i);
    }
}

//Heap sort
void heap_sort(int arr[],int n){
    build_max_heap(arr,n);
    for(int i=n-1;i>=1;i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        max_heapify(arr,i-1,0);
    }
}

//Priority Queue using Max Heap
int heap_maximum(int arr[],int n){
    if (n<1){
        printf("Error: Heap underflow!\n");
        return 0;
    }
    return arr[0];
}
int max_heap_extract_max(int arr[],int* n){
    int max = heap_maximum(arr,*n);
    arr[0] = arr[*n-1];
    (*n)--;
    max_heapify(arr,*n,0);
    return max;
}

void max_heap_increase_key(int arr[],int i,int key){
    if(key<arr[i]){
        printf("Error: New key is smaller than current key!\n");
        return;
    }
    arr[i] = key;
    while(i>0 && arr[parent(i)]<arr[i]){
        int temp=arr[i];
        arr[i]=arr[parent(i)];
        arr[parent(i)]=temp;
        i=parent(i);
    }
}

void max_heap_insert(int arr[],int* n,int key){
    (*n)++;
    arr[*n-1]=-10000;
    max_heap_increase_key(arr,*n-1,key);
}
