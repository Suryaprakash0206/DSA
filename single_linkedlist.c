#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *insert(int data,struct node *ptr){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    ptr->link=temp;
    return temp;
}
void insert_at_tail(int data,struct node *ptr){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;
}
struct node *insert_at_head(int data,struct node *ptr){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=ptr;
    return temp;
}
void insert_at_pos(int data,struct node *ptr,int p){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    struct node *t=ptr;
    p--;
    while(p!=0){
        t=ptr;
        ptr=ptr->link;
        p--;
    }
    t->link=temp;
    temp->link=ptr;
}
void del_at_tail(struct node *ptr){
    struct node *temp=NULL;
    while(ptr->link!=NULL){
        temp=ptr;
        ptr=ptr->link;
    }
    temp->link=NULL;
    free(ptr);
}
struct node *del_at_head(struct node *ptr){
    struct node *temp=ptr->link;
    free(ptr);
    return temp;
}
void del_at_pos(struct node *ptr,int p){
    struct node *temp=NULL;
    p--;
    while(p!=0){
        temp=ptr;
        p--;
        ptr=ptr->link;
    }
    temp->link=ptr->link;
    free(ptr);
}
void traversal(struct node *ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}
int main(){
    struct node *head=malloc(sizeof(struct node));
    head->data=131;
    head->link=NULL;
    struct node *ptr=head;
    ptr=insert(132,ptr);
    ptr=insert(133,ptr);
   // ptr=insert(134,ptr);
    ptr=insert(135,ptr);

    ptr=head;
    traversal(ptr);
    ptr=head;
    insert_at_tail(136,ptr);
    traversal(ptr);
    head=insert_at_head(130,head);
    ptr=head;
    traversal(ptr);
    insert_at_pos(134,ptr,5);
    traversal(ptr);
    ptr=head;
    del_at_tail(ptr);
    traversal(ptr);
    ptr=head;
    head=del_at_head(ptr);
    ptr=head;
    traversal(ptr);
    ptr=head;
    del_at_pos(ptr,3);
    ptr=head;
    traversal(ptr);
}