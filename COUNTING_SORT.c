//This program will work for every integer
#include<stdio.h>

int main(){
    printf("Enter the size of array: ");
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("arr[%d]: ",i);
        scanf("%d",&a[i]);
    }
    printf("Array before sorting: ");
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }   
    int max = a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    int min = a[0];
    for(int w=1;w<n;w++){
        if(a[w]<min){
            min=a[w];
        }
    }
    int c[max-min+1];
    int b[n];
    int index_of_zero= -min;
    for(int j=0;j<=max-min;j++){
        c[j]=0;
    }
    for(int l=0;l<n;l++){
        c[a[l]+index_of_zero]++;
    }
    for(int m=1;m<=max-min;m++){
        c[m]=c[m]+c[m-1];
    }
    for(int o=n-1;o>=0;o--){
        b[c[a[o]+index_of_zero]-1]=a[o];
        c[a[o]+index_of_zero]--;
    }
    printf("\nArray after sorting: ");
    for(int p=0;p<n;p++){
        printf("%d ",b[p]);
    }
    return 0;
}
