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
        leftAns = searchInBST(root->left, target);
    }
    return rightAns || leftAns;
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

Node* deleteFromBST(Node* root, int target){
    // steps to do
    /// target ko dhundo
    /// target ko delete kro

    if(root == NULL) return NULL;

    if(root->data == target){
        // ab delete krenge 
        // 4 cases

        //$1 Leaf Node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //$2 Left is non NULL and right is NULL
        else if(root->left != NULL && root->right == NULL){
            Node* childSubTree = root->left;
            delete root;
            return childSubTree;
        }
        //$3 Left is NULL and right is non NULL
        else if(root->left == NULL && root->right != NULL){
            Node* childSubTree = root->right;
            delete root;
            return childSubTree;
        }
        //$4 left is non NULL and right is non NULL
        else{
            //a -> left subTree ki max value lao
            Node* maxi = maxValue(root->left);
            // replacement
            root->data = maxi->data;

            // delete actual maxi wali node
            root->left = deleteFromBST(root->left, maxi->data);
            return root;
        }
        
    }else if(root->data > target){
        // left mein chalo
        root->left = deleteFromBST(root->left, target);
    }else{
        // right mein jao
        root->right = deleteFromBST(root->right, target);
    }
    return root;
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


int main() {
    Node* root = nullptr;
    createBST(root);
    cout << endl;

    int target = -1;
    cout << "Enter the value of target: " << endl;
    cin >> target;

    while(target != -1){
        root = deleteFromBST(root, target);
        cout << endl << "Printing level order traversal: " << endl;
        levelOrderTraversalPrint(root);
        cout << "Enter the value of target: " << endl;
        cin >> target;
    }


    return 0;
}
