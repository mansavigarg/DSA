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


void preOrderTraversal(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root){
    if(root == NULL) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}


int main() {
    Node* root = nullptr;

    // // Insert values into BST
    // int values[] = {50, 30, 20, 40, 70, 60, 80};
    // for (int val : values) {
    //     root = insert(root, val);
    // }

    // // Display the BST in sorted order
    // cout << "Inorder Traversal: " << endl;
    // levelOrderTraversalPrint(root);


    cout << endl;
    createBST(root);
    cout << endl;
    cout << "Inorder Traversal: " << endl;
    inOrderTraversal(root);
    cout << endl;
    cout << "Postorder Traversal: " << endl;
    postOrderTraversal(root);
    cout << endl;
    cout << "Preorder Traversal: " << endl;
    preOrderTraversal(root);
    cout << endl;
    cout << "Levelorder Traversal: " << endl;
    levelOrderTraversalPrint(root);

    return 0;
}
