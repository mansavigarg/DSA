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


// It returns the root node of created tree
Node* createTree(){
    cout << "Enter the value for Node: " << endl;
    int data;
    cin >> data; 

    if(data == -1){
        return NULL;
    }

    // Step 1: create node
    Node* root = new Node(data);

    // Step 2: create left subtree
    // cout << "Left of Node: " << root->data << endl;
    root->left = createTree();
    // Step 3: create right subtree
    // cout << "Right of Node: " << root->data << endl;
    root->right = createTree();

    return root;
}

int main(){
    Node* root = createTree();
    cout << root->data << endl;
    return 0;
}