#include<bits/stdc++.h>
using namespace std;

struct node{
    int val ;
    node *left,*right;
    node(int key){
        val=key;
        left=NULL;
        right=NULL;
    }
};

    node* add(node *curr,int key){
        if(curr==NULL){
            node*n=new node(key);
            return n;
        }
        if(key>curr->val){
            curr->right=add(curr->right,key);
        }
        else if(key<curr->val){
            curr->left=add(curr->left,key);
        }
        return curr;
    }
    void inorder(node * node){
        if(node!=NULL){
            inorder(node->left);
            cout<<node->val<<" ";
            inorder(node->right);
        }
    }


node* minvalue(node* current){
    node* curr=current;
    while(curr&&curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
node* Delete(node* root,int key){
    if(root==NULL){
        return root;
    }
    if(key<root->val){
        root->left=Delete(root->left,key);
    }
    else if(key>root->val){
        root->right=Delete(root->right,key);
    }
    else {
        if(root->left==NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
            node* temp=minvalue(root->right);
            root->val=temp->val;
            Delete(root->right,temp->val);


    }
    return root;

}
int main(){
    node* root=NULL;
    root =add(root,50);
    add(root,30);
    add(root,20);
    add(root,40);
    add(root,70);
    add(root,60);
    add(root,80);
    inorder(root);
    cout<<"\n";
    root =Delete(root,60);
    inorder(root);
    cout<<"\n";
    root =Delete(root,15);
    inorder(root);
    cout<<"\n";
    root=add(root,25);
    inorder(root);
}
