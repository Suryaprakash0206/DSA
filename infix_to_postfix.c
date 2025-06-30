#include<stdio.h>
#define max 100
char stack[max];
char res[max+1];
int top=-1;
int priority(char c){
    if(c=='^'){
        return 3;
    }
    else if (c=='/' || c=='*'){
        return 2;
    }
    else if (c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
void postfix(char str[]){
    int k=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]>='A' && str[i]<='Z' || str[i]>='a' && str[i]<='z' || str[i]>='0' && str[i]<='9'){
            res[k]=str[i];
            k++;
        }
        else if (str[i]=='('){
            stack[++top]=str[i];
        }
        else if (str[i]==')'){
            while(top!=-1 && stack[top]!='('){
                res[k]=stack[top];
                top--;
                k++;
            }
            top--;
        }
        else{
            while(top!=-1 && priority(str[i])<=priority(stack[top])){
                res[k]=stack[top];
                top--;
                k++;
            }
            stack[++top]=str[i];
        }
    }
    while(top!=-1){
        res[k]=stack[top];
        top--;
        k++;
    }
    res[k]='\0';
}
int main(){
    char str[]={"a+b*(c^d-e)"};
    postfix(str);
    for(int i=0;res[i]!='\0';i++){
        printf("%c",res[i]);
    }
}