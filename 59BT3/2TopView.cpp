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

Node* createTree(){
    cout << "Enter the value for Node: ";
    int value;
    cin >> value;

    if(value == -1) return NULL;
    Node* root = new Node(value);

    root->left = createTree();
    root->right = createTree();
    return root;
}


void printTopView(Node* root){
    map<int, int> hdToNodemap;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // check if it is present in map or not, and if not then store the value in map
        if(hdToNodemap.find(hd) == hdToNodemap.end()){
            hdToNodemap[hd] = frontNode->data;
        }

        // child ko push krna hai 
        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    cout << "Printing " << endl;
    for(auto i : hdToNodemap){
        cout << i.second << " ";
    }
}


void printBottomView(Node* root){
    map<int, int> hdToNodemap;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // always strong the ans in the map so that we can get the lowest ans for the levels
        hdToNodemap[hd] = frontNode->data;

        // child ko push krna hai 
        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    cout << "Printing " << endl;
    for(auto i : hdToNodemap){
        cout << i.second << " ";
    }
}



int main(){
    Node* root = createTree();
    printBottomView(root);
    return 0;
}

// 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1