#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
        Node(){
            this->next = NULL;
            this->prev = NULL;
        }
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

void printDLL(Node* head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    // LL is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        // LL is not empty

        Node* newNode = new Node(data);
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node* head, Node* tail, int data){
    // if LL is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;    
    }
    else{
        // LL is not empty
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position){
    // Empty LL
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }else{
        int length = getLength(head);
        if(position == 1){
            insertAtHead(head,tail,data);
        }
        else if(position == length + 1){
            insertAtTail(head,tail,data);
        }
        else{
            // insert at Middle
            // create newNode
            Node* newNode = new Node(data);
            // set prev and curr pointer
            Node* prevNode = NULL;
            Node* currNode = head;
            while(position != 1){
                position--;
                prevNode = currNode;
                currNode = currNode->next;
            }
            // update pointers
            prevNode->next = newNode;
            newNode->prev = prevNode;
            newNode->next = currNode;
            currNode->prev = newNode;
        }
    }
}

void deleteNode(Node* &head, Node* &tail, int position){
    //! Empty LL
    if(head == NULL){
        // LL is empty
        cout << "Cannot Delete" << endl;
        return;
    }

    //! Single Element
    if(head == tail){
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }

    int length = getLength(head);

    //! Delete from head
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    //! Delete from tail
    else if (position == length){
        Node* prevNode = tail->prev;
        prevNode->next = NULL;
        tail->prev = NULL;
        delete tail;
        tail = prevNode;
    }
    //! Delete from Middle
    else{
        // set prevNode, currNode, nextNode
        Node* prevNode = NULL;
        Node* currNode = head;
        while(position != 1){
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        Node* nextNode = currNode->next;

        // isolate the node by updating pointers
        prevNode->next = nextNode;
        currNode->prev = NULL;
        
        currNode->next = NULL;
        nextNode->prev = prevNode;

        //delete the node
        delete currNode;
    }

}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);

    printDLL(head);

    deleteNode(head,tail,1);
    printDLL(head);
    deleteNode(head,tail,1);
    printDLL(head);
    deleteNode(head,tail,1);
    printDLL(head);
    deleteNode(head,tail,1);
    printDLL(head);
    deleteNode(head,tail,1);
    printDLL(head);
    cout << "Length of LL is " << getLength(head) << endl;
    deleteNode(head,tail,1);
    return 0;
}