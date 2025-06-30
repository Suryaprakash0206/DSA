#include <stdio.h>

struct node {
    int val;
    struct node *left;
    struct node *right;
};
struct node *create_a_node(int val){
    struct node *temp=malloc(sizeof(struct node));
    temp->val=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node *insert(struct node *root,int val){
    if(root==NULL){
        return create_a_node(val);
    }
    
    if(val<root->val){
        root->left=insert(root->left,val);
    }
    else if(val > root->val){
        root->right=insert(root->right,val);
    }
    return root;
}
struct node *findmin(struct node *root){
    if(root->left==NULL) return root;
    return findmin(root->left);
}
struct node *delete(struct node *root,int val){
    if(root==NULL) return NULL;
    if(val < root->val){
        root->left=delete(root->left,val);
    }
    else if(val > root->val){
        root->right=delete(root->right,val);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        else if (root->left==NULL || root->right==NULL){
            struct node *t;
            if(root->left==NULL){
                t=root->right;
            }else{
                t=root->left;
            }
            free(root);
            return t;
        }
        else{
            struct node *temp=findmin(root->right);
            root->val=temp->val;
            root->right=delete(root->right,temp->val);
            
        }
    }
    
}
void inorder(struct node *root){
    if(root==NULL) return ;
    
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}
int main() {
        int n;
        scanf("%d",&n);
        struct node *root=NULL;
        int val;
        scanf("%d",&val);
        root=insert(root,val);
        for(int i=1;i<n;i++){
            scanf("%d",&val);
            insert(root,val);
        }
       inorder(root);
       printf("\n");
       int p;
       p=13;
       delete(root,p);
       inorder(root);
}

