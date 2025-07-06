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

// Convert this BST into sorted Doubly LinkedList

void convertBSTtoDLL(Node* root, Node* &head){
    if(root == NULL) return;

    // RNL traversal

    // R
    convertBSTtoDLL(root->right, head);

    // N

    //$ attaching next pointer of current node to head of LL 
    //$ yha pr conditon check krne ki zarurat ni hai as root null nahi hai (upr check kr liya) so root ka right exist krta hoga
    root->right = head; 

    //$ attaching prev pointer of head of LL to current node
    //$ yha pr check krne ki zarurat hai as if LL empty ho to head ka left not exist
    if(head != NULL) 
        head->left = root;

    //$ updating head
    head = root;

    // R
    convertBSTtoDLL(root->left, head);
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

    int inorder[] = {11,12,13,14,15,16,17};
    int size = 7;
    int s = 0;
    int e = size - 1;

    Node* root = bstFromInorder(inorder, s, e);

    levelOrderTraversalPrint(root);

    Node* head = NULL;
    convertBSTtoDLL(root,head);
    printLL(head);
    return 0;
}
