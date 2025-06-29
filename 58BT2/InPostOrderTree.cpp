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


void createMapping(int inOrder[], int size, map<int,int> &valueToIndexMap){
    for(int i = 0; i < size; i++){
        int element = inOrder[i];
        int index = i;
        valueToIndexMap[element] = index;
    }
}

Node* constructTree(map<int,int> &valueToIndexMap, int postOrder[], int inOrder[], int &postIndex, int inOrderStart, int inOrderEnd, int size){
    // base case
    if(postIndex < 0 || inOrderStart > inOrderEnd){
        return NULL;
    }

    // 1 case mein solve krunga
    int element = postOrder[postIndex];
    postIndex--;
    Node* root = new Node(element);
    //element search krna hoga inorder mein
    // int position = searchInorder(inOrder, size, element); // this is a heavy operation as we are doing the search again and again so we can use map here to do find the element in O(1) time.
    int position = valueToIndexMap[element];


    // baki recursion
    root->right = constructTree(valueToIndexMap, postOrder, inOrder, postIndex, position + 1, inOrderEnd, size);
    root->left = constructTree(valueToIndexMap, postOrder, inOrder, postIndex, inOrderStart, position - 1, size);

    return root;
}

int main(){
    int inOrder[] = {8,14,6,2,10,4}; 
    int postOrder[] = {8,6,14,4,10,2};
    int size = 6;
    int postOrderIndex = size - 1;
    int inOrderStart = 0;
    int inOrderEnd = size - 1;
    map<int,int> valueToIndexMap;
    createMapping(inOrder, size, valueToIndexMap);

    Node* root = constructTree(valueToIndexMap, postOrder, inOrder, postOrderIndex, inOrderStart, inOrderEnd, size);
    cout << "Printing the entire tree" << endl;
    levelOrderTraversalPrint(root);
    return 0;
}