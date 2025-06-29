#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void printLL(Node* head){
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp-> data << "->" ;
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* head){
    Node* temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
    
}

void insertAtHead(Node* &head,Node* &tail, int data){

    if(head == NULL){
        // empty LL
        //step1: Create new Node
        Node* newNode = new Node(data);
        //step2: update head
        head = newNode;
        tail = newNode;
    }else{ 
        // non-empty LL

        // create a new node
        Node* newNode = new Node(data);

        // pointing new node to head node
        newNode->next = head;

        // making head to newNode
        head = newNode;
    }
}


void insertAtTail(Node* &head, Node* &tail, int data){

    if(head == NULL){
        // empty LL
        
        // create node 
        Node* newNode = new Node(data);

        //single node mein head and tail point to same node
        head = newNode;
        tail = newNode;

    }else {
        // non-empty LL

        // create new node
        Node* newNode = new Node(data);
        //tail node ko attach kro newNode se
        tail->next = newNode;
        // update tail to new node
        tail = newNode;
    }
}


void createTail(Node* head, Node* &tail){
    
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    // jab y loop khatam hogya hoga
    // then temp wala pointer last wale node pr hoga
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position){

    int length = getLength(head);

    if(position == 1){
        insertAtHead(head,tail,data);
    }
    else if(position == length + 1 ){
        insertAtTail(head,tail,data);
    }
    else{
        // insert at middle

        // step 1: create a new Node
        Node* newNode = new Node(data);
        
        // step 2: traverse prev and curr to psotion
        Node* prev = NULL;
        Node* curr = head;
        while(position != 1){
            prev = curr;
            curr = curr->next;
            position--;
        }

        // step 3: attach  prev to newNode
        prev->next = newNode;
        
        // step 4: attach newNode to curr
        newNode->next = curr;
    }

}


int main(){
    
    // Node* first = new Node(10);
    // Node* second = new Node(20);
    // Node* third = new Node(30);
    // Node* fourth = new Node(40);
    // Node* fifth = new Node(50);

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;

    // Node* head = first;
    // Node* tail = fifth;
    // cout << "Before insert" << endl;
    // printLL(head);

    // insertAtHead(head, tail, 199);

    // cout << "After insert at Head" << endl;
    // printLL(head);

    // insertAtTail(head, tail, 899);

    // cout << "After insert at Tail" << endl;
    // printLL(head);


    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head,tail,10);
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,50);

    printLL(head);

    insertAtPosition(head,tail,4880,4);
    printLL(head);


    return 0;
}