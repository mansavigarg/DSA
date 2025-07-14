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
        cin >> data;
    }
}

void storeInorderTraversal(Node* root, vector<int> &inorder){
    if(root == NULL) return;

    // LNR
    storeInorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    storeInorderTraversal(root->right, inorder);
}

void replaceUsingPostOrder(Node* root, vector<int> in, int &index){
    if(root == NULL) return;

    // LRN
    replaceUsingPostOrder(root->left, in, index);
    replaceUsingPostOrder(root->right, in, index);
    root->data = in[index];
    index++;

}

Node* convertBSTtoMaxHeap(Node* root){
    // store inorder of the BST
    vector<int> inorder;
    storeInorderTraversal(root, inorder);

    // Replace node values with the sorted inorder valuues , using postorder traversal
    int index = 0;
    replaceUsingPostOrder(root, inorder, index);
    return root;
}

int main(){
    Node* root = NULL;
    createBST(root);
    cout << "Printing BST: " << endl;
    levelOrderTraversalPrint(root);

    cout << endl << "Conerting to heap: " << endl;
    root = convertBSTtoMaxHeap(root);
    cout << endl << "Printing to heap: " << endl;
    levelOrderTraversalPrint(root);


    return 0;
}


// 100 50 150 40 60 110 200 20 -1