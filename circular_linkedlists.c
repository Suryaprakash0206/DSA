#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
void delatend(){
    if(head==NULL){
        printf("empty\n");
        return ;
    }
    struct node *temp=head;
    struct node *prev=NULL;
    if(head->next==head){
        free(head);
        head=NULL;
        return ;
    }
    else{
        while(temp->next!=head){
            prev=temp;
            temp=temp->next;
        }
        prev->next=head;
        free(temp);
    }
}
void delatbeg(){
    if(head==NULL){
        printf("empty\n");
        return ;
    }
    struct node *temp=head;
    struct node *h=head;
    if(head->next==head){
        free(head);
        head=NULL;
        return ;
    }
    else{
        while(temp->next!=head){
            temp=temp->next;
        }
        head=head->next;
        temp->next=head;
        free(h);
    }
}
void delatpos(int p){
    if(head==NULL){
        printf("empty\n");
    }
    struct node *temp=head;
    struct node *prev=NULL;
    if(p==1){
        delatbeg();
    }
    int c=1;
    while(c<=p-1 && temp->next!=head){
        prev=temp;
        temp=temp->next;
        c++;
    }  
    prev->next=temp->next;
    free(temp);
    return ;
}
// Insert at end
void insertatlast(int val) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;

    if (head == NULL) {
        temp->next = temp;
        head = temp;
        return;
    }

    struct node *t = head;
    while (t->next != head) {
        t = t->next;
    }

    t->next = temp;
    temp->next = head;
}

// Insert at beginning
void insertatbeg(int val) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;

    if (head == NULL) {
        temp->next = temp;
        head = temp;
        return;
    }

    struct node *t = head;
    while (t->next != head) {
        t = t->next;
    }

    temp->next = head;
    t->next = temp;
    head = temp;  // update head to new node
}

// Insert general (same as insertatlast for simplicity)
void insert(int val) {
    insertatlast(val);
}

// Print list
void print(struct node *ptr) {
    if (ptr == NULL) {
        printf("empty\n");
        return;
    }

    struct node *temp = ptr;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != ptr);
    printf("\n");
}

int main() {
    insert(8);
    insert(9);
    insert(10);
    insert(11);
    print(head);       // Output: 8 9 10 11

    insertatbeg(7);
    print(head);       // Output: 7 8 9 10 11

    insertatlast(12);
    print(head);       // Output: 7 8 9 10 11 12
    delatbeg();
    print(head); 
    delatend();
    print(head);
    delatpos(3);
    print(head);
    return 0;
}
