#include<stdio.h>
#define max 4
int top=-1;
int stack[max];

int isempty(){
    if(top==-1){
        return 1;
    }else {
        return 0;
    }
}

int isfull(){
    if(top==max-1){
        return 1;
    }else{
        return 0;
    }
}

void push(int n){
    if(isfull()){
        return ;
    }
    else{
        top=top+1;
        stack[top]=n;
    }
}

int pop(){
    int x;
    if(isempty()){
        return 1;
    }
    else{
        x=stack[top];
        top=top-1;
    }
    return x;
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    int d=pop();
    printf("%d\n",d);
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
}