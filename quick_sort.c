#include<stdio.h>
int sort(int arr[],int low,int high){
    
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    i++;

        int temp = arr[high];
        arr[high] = arr[i];
        arr[i] = temp;
    return i;
    
}
void quick(int arr[],int low,int high){
    if(low<high){
        int pivot=sort(arr,low,high);
        sort(arr,low,pivot-1);
        sort(arr,pivot+1,high);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quick(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

// TIME COMPLEXICITY --> O(nlogn);
// SPACE COMPLEXICITY --> O(1);
