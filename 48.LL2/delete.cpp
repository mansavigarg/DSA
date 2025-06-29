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


void deleteNode(Node* &head, Node* &tail, int position){

    //! Empty list
    if(head == NULL){
        cout << "Cannot delte as LL is empty" << endl;
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
        // temp ko head pr point krva do
        Node* temp = head;
        // head ko next node pr laga do
        head = head->next;
        // 1st node ko null pr point krva do
        temp->next = NULL;
        // 1st node ko dlt kr do
        delete temp;
    }
    
    //! Delete Tail
    else if(position == length){
        // prev node banao jisko head pr point kr do
        Node* prev = head;
        // prev ko last 2nd node tk lekr jao, means jab tk prev ka next tail ni aa jata tb tk loop chalao
        while(prev->next != tail){
            prev = prev->next;
        }
        // prev k next ko null kr do and last node ko isolate kr do
        prev->next = NULL;
        // last isolated node ko dlt kr do
        delete tail;
        // tail ko prev pr laga do
        tail = prev;
    }

    //! Delete form middle position
    else {
        Node* prev = NULL;
        Node* curr = head;

        while (position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }
        
        prev->next = curr->next;

        curr->next = NULL;

        delete curr;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtPosition(head,tail,10,1);
    insertAtPosition(head,tail,20,2);
    insertAtPosition(head,tail,30,3);
    insertAtPosition(head,tail,40,4);
    insertAtPosition(head,tail,50,5);

    printLL(head);

    deleteNode(head,tail,4);

    printLL(head);
    return 0;
}