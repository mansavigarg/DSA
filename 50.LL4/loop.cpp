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


bool checkLoop(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        // agar khi pr bi fast equal ho jata hai slow k
        if(fast == slow){
            return true;
        }
    }
    return false;
}

Node* getStartingPoint(Node* &head){
    // check for loop
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(slow == fast){
            break;
        }
    }

    // yha paucha means that slow and fast meet kar chuke hai 
    
    // ALGO to check for starting point

    slow = head;
    // slow and fast ko 1 step move krva do and condition mein fast != slow kiya hai kyoki aapne ko pata hai ki kbi na kbi to who meet krnege hi
    while(fast != slow){
        slow = slow->next;
        fast = fast->next;
    }
    // return starting point 
    return slow;
}

void removeLoop(Node* &head){
    Node* startPoint = getStartingPoint(head);

    Node* temp = startPoint;
    while(temp->next != startPoint){
        temp = temp->next;
    }
    temp->next = NULL;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtPosition(head,tail,10,1);
    insertAtPosition(head,tail,20,2);
    insertAtPosition(head,tail,30,3);
    insertAtPosition(head,tail,40,4);
    insertAtPosition(head,tail,50,5);
    tail->next = head->next->next;
    removeLoop(head);
    printLL(head);

    // cout << getStartingPoint(head)->data << endl;

    return 0;
}