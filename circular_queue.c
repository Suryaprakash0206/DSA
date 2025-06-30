#include<stdio.h>
# define size 5
int queue[size];
int front=-1,rear=-1;
int isfull(){
    return front==(rear+1)%size;
}
int isempty(){
    return front==-1;
}
void enqueue(int val){
    if(isfull()){
        printf("queue is full\n");
        return ;
    }
    else if (isempty()){
        front=rear=0;
    }
    else{
        rear=(rear+1)%size;
    }
    queue[rear]=val;
}
void dequeue(){
    if(isempty()){
        printf("queue is empty\n");
    }
    else if (front==rear){
        front=rear=-1;
    }
    else{
        front=(front+1)%size;
    }
}
void print(){
    if(isempty()){
        printf("queue is empty\n");
    }
    int i=front;
    while(1){
        printf("%d ",queue[i]);
        if(i==rear) break;
        i=(i+1)%size;
    }
}
void peek(){
    printf(" peeks elmnt is %d \n",queue[rear]);
}
int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    print();
    printf("\n");
    dequeue();
    print();
    peek();

}