#include<stdio.h>
void sort(int arr[],int low,int mid,int high,int n){
    int i=low;
    int j=mid+1;
    int b[high-low+1];
    int k=0;

    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            b[k++]=arr[i++];
        }else{
            b[k++]=arr[j++];
        }
    }
    while(i<=mid){
        b[k++]=arr[i++];
    }
    while(j<=high){
        b[k++]=arr[j++];
    }
    k=0;
    for(int i=low;i<=high;i++){
        arr[i]=b[k++];
    }
}
void mergesort(int arr[],int low,int high,int n){
    if(low>=high){
        return ;
    }
    int mid=(low+high)/2;
    mergesort(arr,low,mid,n);
    mergesort(arr,mid+1,high,n);

    sort(arr,low,mid,high,n);

}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    mergesort(arr,0,n-1,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}