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

// Inorder traversal (LNR)
void levelOrderTraversalPrint(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    // traversal
    while(!q.empty()){
        Node* front = q.front();
        q.pop();    

        if(front == NULL){
            cout << endl; 
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            // valid wala case
            cout << front->data << " ";
    
            if(front->left != NULL){
                q.push(front->left);
            }
            if(front->right != NULL){
                q.push(front->right);
            } 
        }

    }
}

Node* bstFromInorder(int inorder[], int s, int e){
    // Base case
    if(s > e) return NULL;

    // 1 case khud solve kro
    int mid = (s+e)/2;
    int element = inorder[mid];
    Node* root = new Node(element);

    // baki recursion
    root->left = bstFromInorder(inorder, s, mid-1);
    root->right = bstFromInorder(inorder, mid+1, e);

    return root;
}


int main() {

    int inorder[] = {11,12,13,14,15,16,17};
    int size = 7;
    int s = 0;
    int e = size - 1;

    Node* root = bstFromInorder(inorder, s, e);

    levelOrderTraversalPrint(root);
    return 0;
}
