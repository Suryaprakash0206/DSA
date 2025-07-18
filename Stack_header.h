#ifndef STACK_H
#define STACK_H
#include<iostream>

struct node{
    int data;
    node *next;
    node(int val){
        data = val;
        next = NULL;
    }
};

struct stack{
    node *top = NULL;
    bool isempty(){
        return (top == NULL);
    }
    void push(int val){
        node *temp = new node(val);
        temp->next = top;
        top = temp;
    }
    void pop(){
        if(isempty()) return;
        node *temp = top;
        top = top->next;
        delete temp;
    }
    void peek(){
        if(isempty()) return;
        std :: cout << top->data << " ";
    }
};

#endif ;