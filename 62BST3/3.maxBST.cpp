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

class NodeData{
    public:
        int size;
        int minVal;
        int maxVal;
        bool validBST;

        NodeData(){

        }
        NodeData(int size,int max, int min, bool valid){
            this->size = size;
            maxVal = max;
            minVal = min;
            validBST = valid;
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


NodeData findLargestBST(Node* root, int &ans){
    // base case
    if(root == NULL) {
        NodeData temp(0, INT_MIN, INT_MAX, true);
        return temp;
    }

    NodeData leftAns = findLargestBST(root->left, ans);
    NodeData rightAns = findLargestBST(root->right, ans);

    // checking at node
    NodeData currNodeAns;

    currNodeAns.size = leftAns.size + rightAns.size + 1;
    currNodeAns.maxVal = max(root->data, rightAns.maxVal);
    currNodeAns.minVal = min(root->data, leftAns.minVal);
    if(leftAns.validBST && rightAns.validBST && (root->data > leftAns.maxVal && root->data < rightAns.minVal)){
        currNodeAns.validBST = true;
    }else currNodeAns.validBST = false;

    if(currNodeAns.validBST){
        ans = max(ans, currNodeAns.size);
    }
    return currNodeAns;
}

int main() {

Node* root = new Node(50);
Node* first = new Node(30);
Node* second = new Node(60);
Node* third = new Node(5);
Node* fourth = new Node(20);
Node* fifth = new Node(45);
Node* sixth = new Node(70);
Node* seventh = new Node(65);
Node* eight = new Node(80);

root->left = first;
root->right = second;

first->left = third;
first->right = fourth;

second->left = fifth;
second->right = sixth;

sixth->left = seventh;
sixth->right = eight;


    cout << "Printing the tree " << endl;
    levelOrderTraversalPrint(root);

    int ans = 0;
    findLargestBST(root, ans);
    cout << "-----> " << ans << endl;
    return 0;
}
