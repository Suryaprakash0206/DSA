#include<stdio.h>
#define max 4
int rear=-1;
int front=-1;
int arr[max];
int isempty(){
    if(rear==-1 && front==-1){
        return 1;
    }else{
        return 0;
    }
}

int isfull(){
    if(rear==(sizeof(arr)-1)){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(int n){

    if(isfull()){
        return ;
    }
    else if(isempty()){
        rear=front=0;
    }
    else{
        rear++;
    }
    arr[rear]=n;
}

int dequeue(){
    int x=0; 
    if(isempty()){
        return 1;
    }else if(front==rear){
        x=arr[front];
        front=rear=-1;
    }else{
        x=arr[front];
        front++;
    }
    return x;
}

int main(){

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    int data=dequeue();
    //int data2=dequeue();
\
    printf("count is %d\n",rear-front);
    printf("%d\n",data);
    for(int i=front;i<4;i++){
        printf("%d ",arr[i]);
    }

}