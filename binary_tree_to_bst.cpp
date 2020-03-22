#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node *left, *right;
};

Node* newNode(int data)
{
    // dynamically allocating memory
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
vector<int>v;
 void inorder(Node * node){
        if(node!=NULL){
            inorder(node->left);
            v.push_back(node->data);
            cout<<node->data<<" ";
            inorder(node->right);
        }
    }

int idx=0;
void binary_to_bst(Node *node){
    if(node!=NULL){
        binary_to_bst(node->left);
        node->data=v[idx++];
        binary_to_bst(node->right);
    }

}


int main(){
    Node *root=NULL;
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);
    inorder(root);
    cout<<"\n";
    sort(v.begin(),v.end());
    binary_to_bst(root);
    inorder(root);
}
