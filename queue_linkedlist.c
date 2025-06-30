#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
int isempty(){
    if(rear==NULL){
        return 1;
    }else return 0;
}
void enqueue(int val){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=val;
    if(front==NULL && rear==NULL){
        front=temp;
        rear=temp;
    }else{
        rear->next=temp;
        rear=temp;
    }
}
void dequeue(){
    if(isempty()){
        printf("empty\n");
        return; 
    }
    struct node *temp=front;
    int x=front->data;
    front=front->next;
    free(front);
    printf("del elmnt is %d \n",x);
}
void print(){
    if(rear==NULL){
        printf("emprty\n");
        return ;
    }
    struct node *ptr=front;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
int main(){
    enqueue(130);
    enqueue(131);
    enqueue(132);
    enqueue(133);
    enqueue(134);
    enqueue(135);
    print();
    dequeue();
}