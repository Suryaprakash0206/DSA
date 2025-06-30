#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
struct node *insert(int data,struct node *ptr){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->prev=ptr;
    temp->next=NULL;
    ptr->next=temp;
    return temp;
}
void insert_at_tail(int data,struct node *ptr){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    temp->prev=ptr;
    ptr->next=temp;
}
struct node *insert_at_head(int data,struct node *ptr){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->prev=NULL;
    temp->next=ptr;
    return temp;
}
void insert_at_pos(int data,struct node *ptr,int p){
    struct node *t=malloc(sizeof(struct node));
    t->data=data;
    struct node *temp=NULL;
    p--;
    while(p!=0){
        temp=ptr;
        p--;
        ptr=ptr->next;
    }
    t->next=ptr;
    t->prev=temp;
    temp->next=t;
    ptr->prev=t;
}
void del_at_tail(struct node *ptr){
    struct node *temp=NULL;
    while(ptr->next!=NULL){
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=NULL;
    free(ptr);
}
struct node *del_at_head(struct node *ptr){
    struct node *temp=ptr->next;
    free(ptr);
    return temp;
}
void del_at_pos(struct node *ptr,int p){
    struct node *temp1=ptr->next->next;
    struct node *temp2=ptr;
    p--;
    while(p!=1){
        temp2=temp2->next;
        p--;
        temp1=temp1->next;
    }
    temp2->next=temp1;
    temp1->prev=temp2;
}
void traversal(struct node *ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
int main(){
    struct node *head=malloc(sizeof(struct node));
    head->data=130;
    head->prev=NULL;
    head->next=NULL;
    struct node *ptr=head;
    ptr=insert(131,ptr);
    ptr=insert(132,ptr);
   // ptr=insert(133,ptr);
    ptr=insert(134,ptr);
    ptr=insert(135,ptr);
    ptr=head;
    traversal(ptr);
    insert_at_tail(136,ptr);
    traversal(ptr);
    head=insert_at_head(129,head);
    ptr=head;
    traversal(ptr);
    insert_at_pos(133,head,5);
    traversal(ptr);
    del_at_tail(head);
    traversal(head);
    head=del_at_head(head);
    traversal(head);
    del_at_pos(head,4);
    traversal(head);
}
