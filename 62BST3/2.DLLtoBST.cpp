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

// Convert this DLL into BST

Node* convertDLLtoBST(Node* &head, int n){
    if(head == NULL || n <= 0) return NULL;

    //LNR

    // L
    Node* leftSubTree = convertDLLtoBST(head, n/2);

    // N
    Node* root = head;
    root->left = leftSubTree;
    head = head->right;

    // R
    Node* rightSubTree = convertDLLtoBST(head, n-n/2-1);
    root->right = rightSubTree; 

    
    return root;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->right;
    }
    cout << endl;
}

int main() {

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    first->right = second;
    second->left = first;
    second->right = third;
    third->left = second;

    Node* head = first;

    Node* root = convertDLLtoBST(head,3);
    levelOrderTraversalPrint(root);
    return 0;
}
