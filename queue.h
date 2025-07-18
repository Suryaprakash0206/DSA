#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H
#include<iostream>
struct node{
    int data;
    node * next;
    node(int val){
        data=val;
        next=NULL;
    }
};
struct queue{
    node * head=nullptr;
    node * tail=nullptr;
    void push(int val){
        node *nn=new node(val);
        if(head==nullptr){
            head=nn;
            tail=nn;
        }
        else{
            tail->next=nn;
            tail=tail->next;
        }
    }
    void pop(){
        node *temp=head;
        head=head->next;
        delete temp;
    }
    int front(){
        return head->data;
    }
    bool empty(){
        if(head==nullptr) return 1;
        else return 0;
    }
};

#endif