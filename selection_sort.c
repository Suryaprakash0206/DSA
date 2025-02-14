#include<stdio.h>
void sort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min=i;

        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                min=j;
            }

        }
        int t=arr[i];
         arr[i]=arr[min];
        arr[min]=t;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

// TIME COMPLEXICITY --> O(N^2);
// SPACE COMPLEXICITY --> O(1);
