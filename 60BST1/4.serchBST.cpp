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

bool searchInBST(Node* root, int target){
    if(root == NULL) return false;

    // 1 Case khud solve kr rhe hai 
    if(target == root->data) return true;

    // recursion
    bool leftAns = false;
    bool rightAns = false;
    if(target > root->data){
        rightAns = searchInBST(root->right, target);
    }else{
        leftAns =searchInBST(root->left, target);
    }
    return rightAns || leftAns;
}



int main() {
    Node* root = nullptr;
    createBST(root);
    cout << endl;

    bool ans = searchInBST(root, 490);
    if(ans) cout << "Found";
    else cout << "Not found";


    return 0;
}
