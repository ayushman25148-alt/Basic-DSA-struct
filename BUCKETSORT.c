#include <stdio.h>

void bucket_sort(float arr[], int n){
    float out[10][n];
    int index[10] = {0};   
    for(int i=0;i<n;i++){
        int bucket_index = arr[i] * 10;
        if(bucket_index >= 10) {
            bucket_index = 9; 
        }
        out[bucket_index][index[bucket_index]] = arr[i];
        index[bucket_index]++;
    }
    for(int j=0;j<10;j++){
        if(index[j]>0){
            for(int v=1;v<index[j];v++){
                float key = out[j][v];
                int i = v-1;
                while(i>=0 && out[j][i]>key){
                    out[j][i+1]=out[j][i];
                    i--;
                }
                out[j][i+1]=key;
            }
        }
    }
    
    for(int j=0;j<10;j++){
        for(int l=0;l<index[j];l++){
            arr[k] = out[j][l];
            k++;
        }
    }
    printf("Sorted array: ");
    for(int m=0;m<n;m++){
        printf("%f ",arr[m]);
    }
}
