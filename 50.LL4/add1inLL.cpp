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

    ~Node(){
        cout << "Destructor called for " << this->data << endl;
    }
};

void printLL(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position){
    int length = getLength(head);

    //insert at head
    if(position == 1){
        if(head == NULL){
            Node *newNode = new Node(data);
            head = newNode;
            tail = newNode;
        }else{
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        }
    }

    // insert at tail
    else if(position == length+1){
        if(head == NULL){
            Node* newNode = new Node(data);
            head = newNode;
            tail = newNode;
        }else{
            Node* newNode = new Node(data);
            tail->next = newNode;
            tail = newNode;
        }
    }

    // insert at middle
    else{
        Node* newNode = new Node(data);

        Node* prev = NULL;
        Node* curr = head;

        while(position != 1){
            prev = curr;
            curr = curr->next;
            position--;
        }

        prev->next = newNode;
        newNode->next = curr;
    }
}


Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

void addOne(Node* &head){
     
    head = reverse(head);

    Node* temp = head;
    int carry = 1;

    while(temp->next != NULL){
        int totalSum = temp->data + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;

        temp->data = digit;
        temp = temp->next;

        if(carry == 0){
            break;
        }
    }

    // last node processing
    if(carry != 0){
        int totalSum = temp->data + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;

        temp->data = digit;
        if(carry != 0){
            Node* newNode = new Node(carry);
            temp->next = newNode;
        }
    }

    head = reverse(head);
}



int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtPosition(head,tail,9,1);
    insertAtPosition(head,tail,9,2);
    insertAtPosition(head,tail,9,3);
    // insertAtPosition(head,tail,40,4);
    // insertAtPosition(head,tail,50,5);
    printLL(head);

    addOne(head);

    printLL(head);

    return 0;
}