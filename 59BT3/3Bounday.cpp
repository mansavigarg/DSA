#include<iostream>
#include<map>
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
    cout << "Enter the value for Node: ";
    int value;
    cin >> value;

    if(value == -1) return NULL;
    Node* root = new Node(value);

    root->left = createTree();
    root->right = createTree();
    return root;
}

void printLeftBoundary(Node* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;
    cout << root->data << " ";
    if(root->left != NULL) printLeftBoundary(root->left);
    else printLeftBoundary(root->right);
}

void printLeafBoundary(Node* root){
    if(root == NULL) return;
    if(root->left == NULL and root->right == NULL) cout << root->data << " ";
    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

void printRightBoundary(Node* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;
    if(root->right != NULL) printRightBoundary(root->right);
    else printRightBoundary(root->left);
    cout << root->data << " ";
}

void boundaryTraverse(Node* root){
    if(root == NULL) return;
    if(root->left != NULL || root->right != NULL) cout << root->data << " ";
    printLeftBoundary(root->left);
    printLeafBoundary(root);
    printRightBoundary(root->right);

}

int main(){
    Node* root = createTree();

    boundaryTraverse(root);

    return 0;
}

// 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1