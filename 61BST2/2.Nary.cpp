#include <iostream>
using namespace std;

// Node class for N-ary Tree
class Node {
public:
    int data;
    int children_count;
    Node** children;

    // Constructor
    Node(int val) {
        data = val;
        children_count = 0;
        children = nullptr;
    }
};

// Function to take input recursively
Node* takeInput() {
    int data, count;
    cout << "Enter node data: ";
    cin >> data;

    cout << "Enter number of children for node " << data << ": ";
    cin >> count;

    Node* root = new Node(data);
    root->children_count = count;
    root->children = new Node*[count];  // allocate array for children

    for (int i = 0; i < count; i++) {
        root->children[i] = takeInput();  // recursively take input for children
    }

    return root;
}

// Level-order traversal (Breadth First)
void levelOrderTraversal(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        for (int i = 0; i < current->children_count; i++) {
            q.push(current->children[i]);
        }
    }
}

int main() {
    cout << "Build N-ary Tree\n";
    Node* root = takeInput();

    cout << "\nPreorder Traversal of the N-ary Tree:\n";
    levelOrderTraversal(root);

    return 0;
}
