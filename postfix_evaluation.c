#include<stdio.h>
#define max 100
int stack[max];
int top=-1;
int postfix(char str[]){
    for(int i=0;str[i]!='\0';i++){
        if(str[i]>='0' && str[i]<='9'){
            stack[++top]=str[i]-'0';
        }
        else{
            if (top < 1) {
                printf("Error: Stack Underflow or invalid expression\n");
                return -1; // Indicate error
            }
            int a=stack[top];
            top--;
            int b=stack[top];
            top--;
            if(str[i]=='+'){
                top++;
                stack[top]=a+b;
            }
            else if (str[i]=='-'){
                top++;
                stack[top]=b-a;
            }
            else if (str[i]=='/'){
                if(a==0) return -1;
                top++;
                stack[top]=b/a;
            }
            else{
                top++;
                stack[top]=a*b;
            }
        }
    }
    return stack[top];
}
int main(){
    char str[]={"24+5/"};
    int res=postfix(str);
    printf("%d\n",res);
}