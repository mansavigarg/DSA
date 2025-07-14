#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(){

    }
    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Info{
    public:
        int maxVal;
        bool isHeap;
        Info(){

        }
        Info(int val, bool flag){
            this->maxVal = val;
            this->isHeap = flag;
        }
};

Info checkMaxHeap(Node* root){
    // Base case
    if(root == NULL){
        Info temp;
        temp.maxVal = INT_MIN;
        temp.isHeap = true;
        return temp;
    }
    if(root->left == NULL && root->right == NULL){
        Info temp;
        temp.maxVal = root->data;
        temp.isHeap = true;
        return temp;
    }

    // baki recursion
    Info leftAns = checkMaxHeap(root->left);
    Info rightAns = checkMaxHeap(root->right);

    // 1 case khud krunga
    if(root->data > leftAns.maxVal && root->data > rightAns.maxVal && leftAns.isHeap && rightAns.isHeap){
        Info ans ;
        ans.maxVal = root->data;
        ans.isHeap = true;
        return ans;
    }else{
        Info ans;
        ans.maxVal = max(root->data, max(leftAns.maxVal, rightAns.maxVal));
        ans.isHeap = false;
        return ans;
    }
}


pair<int, bool> checkingMaxHeap(Node* root){
    // Base case
    if(root == NULL){
        return {INT_MIN, true};
    }
    if(root->left == NULL && root->right == NULL){
        return {root->data, true};
    }

    // Recursion
    pair<int, bool> leftAns = checkingMaxHeap(root->left);
    pair<int, bool> rightAns = checkingMaxHeap(root->right);

    bool leftValid = (root->left == NULL || root->data >= root->left->data);
    bool rightValid = (root->right == NULL || root->data >= root->right->data);

    bool isHeap = leftAns.second && rightAns.second && leftValid && rightValid;

    int maxVal = max(root->data , max(leftAns.first , rightAns.first));
    return {maxVal, isHeap};
}

bool chechHeapAgain(Node* root){
    if(root == NULL) {
        return true;
    }
    if(root->left == NULL && root->right == NULL){
        return true;
    }

    bool leftAns = chechHeapAgain(root->left);
    bool rightAns = chechHeapAgain(root->right);

    bool leftValid = (root->left == NULL || root->data >= root->left->data);
    bool rightValid = (root->right == NULL || root->data >= root->right->data);

    if(leftAns && rightAns && leftValid && rightValid ){
        return true;
    }else return false;
}


Node* buildSampleTree() {
    /*
            50
           /  \
         30    40
        / \     \
      10  20     35
    */
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(40);
    root->left->left = new Node(10);
    root->left->right = new Node(20);
    root->right->right = new Node(35);

    return root;
}

int main() {
    Node* root = buildSampleTree();

    Info result = checkMaxHeap(root);

    if (result.isHeap) {
        cout << "The binary tree is a Max Heap." << endl;
    } else {
        cout << "The binary tree is NOT a Max Heap." << endl;
    }

    cout << endl << endl;


    pair<int, bool> newresult = checkingMaxHeap(root);

    if (newresult.second) {
        cout << "The binary tree is a Max Heap." << endl;
    } else {
        cout << "The binary tree is NOT a Max Heap." << endl;
    }
    cout << endl << endl;


    bool newresultHeap = chechHeapAgain(root);

    if (newresultHeap) {
        cout << "The binary tree is a Max Heap." << endl;
    } else {
        cout << "The binary tree is NOT a Max Heap." << endl;
    }

    return 0;
}