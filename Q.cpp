#include<iostream>
#include"queue.h"
using namespace std;

int main(){
    queue Q;
    Q.push(10);
    Q.push(20);
    Q.push(30);
    Q.push(40);
    Q.push(50);
    while(!Q.empty()){
        cout<<Q.front()<<" ";
        Q.pop();
    }
}