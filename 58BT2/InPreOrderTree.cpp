#include<iostream>
#include<map>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

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

Node* createTree(){
    cout << "Enter the value for Node: " << endl;
    int data;
    cin >> data; 

    if(data == -1){
        return NULL;
    }

    // Step 1: create node
    Node* root = new Node(data);

    // Step 2: create left subtree
    // cout << "Left of Node: " << root->data << endl;
    root->left = createTree();
    // Step 3: create right subtree
    // cout << "Right of Node: " << root->data << endl;
    root->right = createTree();

    return root;
}


int searchInorder(int inOrder[], int size, int element){
    for(int i = 0; i < size; i++){
        if(inOrder[i] == element){
            return i;
        }
    }
    return -1;
}

void createMapping(int inOrder[], int size, map<int,int> &valueToIndexMap){
    for(int i = 0; i < size; i++){
        int element = inOrder[i];
        int index = i;
        valueToIndexMap[element] = index;
    }
}

Node* constructTree(map<int,int> &valueToIndexMap, int preOrder[], int inOrder[], int &preIndex, int inOrderStart, int inOrderEnd, int size){
    // base case
    if(preIndex >= size || inOrderStart > inOrderEnd){
        return NULL;
    }

    // 1 case mein solve krunga
    int element = preOrder[preIndex];
    preIndex++;
    Node* root = new Node(element);
    //element search krna hoga inorder mein
    // int position = searchInorder(inOrder, size, element); // this is a heavy operation as we are doing the search again and again so we can use map here to do find the element in O(1) time.
    int position = valueToIndexMap[element];


    // baki recursion
    root->left = constructTree(valueToIndexMap, preOrder, inOrder, preIndex, inOrderStart, position - 1, size);
    root->right = constructTree(valueToIndexMap, preOrder, inOrder, preIndex, position + 1, inOrderEnd, size);

    return root;
}

int main(){
    int inOrder[] = {10,8,6,2,4,12}; 
    int preOrder[] = {2,8,10,6,4,12};
    int size = 6;
    int preOrderIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = size - 1;
    map<int,int> valueToIndexMap;
    createMapping(inOrder, size, valueToIndexMap);

    Node* root = constructTree(valueToIndexMap, preOrder, inOrder, preOrderIndex, inOrderStart, inOrderEnd, size);
    cout << "Printing the entire tree" << endl;
    levelOrderTraversalPrint(root);
    return 0;
}