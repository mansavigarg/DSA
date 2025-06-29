#include<iostream>
using namespace std;

class Queue{
    public:
        int *arr;
        int size;
        int front;
        int rear;

        Queue(int size){
            arr = new int[size];
            this->size = size;
            front = -1;
            rear = -1;
        }

        void push(int val){
            // Check if queue is full
            if(rear == size-1){
                cout << "OverFlow, Queue is full." << endl;
                return;
            } 
            else if(front == -1 && rear == -1){
                // empty case
                front++;
                rear++;
                arr[rear] = val;
            }
            else{
                // normal case
                rear++;
                arr[rear] = val;
            }
        }

        void pop(){
            // UnderFlow
            if(front == -1 && rear == -1){
                cout << "Queue UnderFlow" << endl;
                return;
            }
            else if(front == rear){
                // single element case
                arr[front] = -1;
                front = -1;
                rear = -1;
            }
            else{
                //normal case
                arr[front] = -1;
                front++;
            }
        }

        bool isEmpty(){
            if(front == -1 && rear == -1){
                return true;
            }else{
                return false;
            }
        }

        int getSize(){
            if(front == -1 && rear == -1){
                return 0;
            }else {
                return rear - front + 1;
            }
        }

        int getFront(){
            if(front == -1){
                cout << "No element in queue, cannot give front element." << endl;
                return -1;
            }else{
                return arr[front];
            }
        }

        int getRear(){
            if(rear == -1){
                cout << "No element in queue, cannot give rear element." << endl;
                return -1;
            }else{
                return arr[rear];
            }
        }

        void print(){
            cout << "Printing Queue: " ;
            for(int i = 0; i < size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    // Creation
    Queue q(5);
    q.print();

    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);

    q.print();

    cout << "Size of Queue: " <<  q.getSize() << endl;
    
    q.pop();
    q.print();

    cout << "Size of Queue: " <<  q.getSize() << endl;

    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;

    cout << "Queue is empty or not: " << q.isEmpty() << endl;

    q.push(100);
    q.print();

    q.pop();
    q.pop();
    q.pop();
    q.pop();

    q.print();
    cout << "Size of Queue: " <<  q.getSize() << endl;
    return 0;
}