#include <stdio.h>

void radix_sort(int arr[], int n){
    int max = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    for(int exp=1;max/exp>0;exp*=10){
        int output[n];
        int count[10]={0};
        for(int j=0;j<n;j++){
            count[(arr[j]/exp)%10]++;
        }
        for(int k=1;k<10;k++){
            count[k]=count[k]+count[k-1];
        }
        for(int l=n-1;l>=0;l--){
            output[count[(arr[l]/exp)%10]-1]=arr[l];
            count[(arr[l]/exp)%10]--;
        }
        for(int m=0;m<n;m++){
            arr[m]=output[m];
        }
    }
    printf("Sorted array: ");
    for(int p=0;p<n;p++){
        printf("%d ",arr[p]);
    }
}
