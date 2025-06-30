#include<stdio.h>
#include<math.h>
void radix(int arr[], int n){
    int div=1;
    

    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int steps=(int)log10(max)+1;
    
    for(int i=1;i<=steps;i++){
        int b[10][n];
        int count[10]={0};
        for(int i=0;i<n;i++){
        int l=(arr[i]/div)%10;
        b[l][count[l]++]=arr[i];
        }
    int k=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<count[i];j++){
            arr[k++]=b[i][j];
        }
    }
    div=div*10;
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    radix(arr,n);
    print(arr,n);
    return 0;
}