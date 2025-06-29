#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* createTree(){
    cout << "Enter the value for Node: " << endl;
    int data;
    cin >> data; 

    if(data == -1){
        return NULL;
    }
    Node* root = new Node(data);
    root->left = createTree();
    root->right = createTree();

    return root;
}

void preOrderTraversal(Node* root){
    // Base case
    if(root == NULL){
        return;
    }
    // N L R

    // N
    cout << root->data << " ";
    // L
    preOrderTraversal(root->left);
    // R
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root){
    // Base case
    if(root == NULL){
        return;
    }
    // L N R

    // L
    inOrderTraversal(root->left);
    // N
    cout << root->data << " ";
    // R
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    // Base case
    if(root == NULL){
        return;
    }
    // L R N

    // L
    postOrderTraversal(root->left);
    // R
    postOrderTraversal(root->right);
    // N
    cout << root->data << " ";
}


int main(){
    Node* root = createTree();
    //  cout << root->data << endl;

    cout << "PreOrder: ";
    preOrderTraversal(root);
    cout << endl;
    cout << "InOrder: ";
    inOrderTraversal(root);
    cout << endl;
    cout << "PostOrder: ";
    postOrderTraversal(root);

    return 0;
}