#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *right;
    struct node *left;
};
struct node *new(int val){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node *insert(struct node *root,int val){
    if(root==NULL){
        root=new(val);
    }
    if(val < root->data){
        root->left=insert(root->left,val);
    }
    if(val > root->data){
        root->right=insert(root->right,val);
    }
    return root;
}
void inorder(struct node *root){
    if(root==NULL) return;
    
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int main() {
	int n;
	scanf("%d",&n);
	int val;
	scanf("%d",&val);
	struct node *root = NULL;
	root=insert(root,val);
	for(int i = 1 ; i < n ; i++){
	    scanf("%d",&val);
	   // printf("%d ",val);
	    insert(root,val);
	}
	inorder(root);
}

