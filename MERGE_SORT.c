#include <stdio.h>
#include <stdlib.h>

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
