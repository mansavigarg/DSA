#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a value in BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

void createBST(Node* &root){
    cout << "Enter Data: " ;
    int data;
    cin >> data;

    while(data != -1){
        root = insert(root,data);
        cout << "Enter Data: " ;
        cin >> data;
    }
}

Node* minValue(Node* root){
    if(root == NULL){
        cout << "No min value" << endl;
        return NULL;
    }
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
Node* maxValue(Node* root){
    if(root == NULL){
        cout << "No min value" << endl;
        return NULL;
    }
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}


int main() {
    Node* root = nullptr;
    createBST(root);
    cout << endl;

    Node* minNode = minValue(root);
    if(minNode == NULL){
        cout << "There is no node in tree" << endl;
    }else cout << "Min value is " << minNode->data << endl;
    Node* maxNode = maxValue(root);
    if(minNode == NULL){
        cout << "There is no node in tree" << endl;
    }else cout << "Max value is " << maxNode->data << endl;

    return 0;
}
