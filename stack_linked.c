#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *top=NULL;
int size=0;
void push(int val){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=val;
    temp->next=top;
    top=temp;
    size++;
}
int pop(){
    struct node *temp=top;
    if(top==NULL){
        return 0;
    }
    int x=top->data;
    top=top->next;
    free(temp);
    return x;
}
void print(){
    if(top==NULL){
        printf("stack is empty\n");
    }
    struct node *ptr=top;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
void peek(){
    if(top==NULL){
        printf("empty\n");
    }
        printf("peek is %d\n",top->data);
}
int get_size(){
    return size;
}
int empty(){
    if(top==NULL){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    print();
    int delete = pop();
    print();
    peek();
    int size=get_size();
}