#include<iostream>
using namespace std;

class CQueue{
    public:
        int *arr;
        int size;
        int front;
        int rear;

        CQueue(int size){
            arr = new int[size];
            this->size = size;
            front = -1;
            rear = -1;
        }

        void push(int val){

            // Check if queue is full (OverFlow Condition)
            //here in the condition we do make mistakes as we need to check all the conditions
            if((front == 0 && rear == size-1) || (rear == front - 1)){
                cout << "OverFlow, Queue is full." << endl;
                return;
            } 
            else if(front == -1 && rear == -1){
                // empty case
                front++;
                rear++;
                arr[rear] = val;
            }
            else if(rear == size - 1 && front != 0){
                //# CIRCULAR NATURE
                rear = 0;
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
            else if(front == size - 1){
                //# CIRCULAR NATURE
                arr[front] = -1;
                front = 0;
            }
            else{
                //normal case
                arr[front] = -1;
                front++;
            }
        }

        void print(){
            cout << "Front: " << front << " Rear: " << rear << endl;
            cout << "Printing Queue: " ;
            for(int i = 0; i < size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    // Creation
    CQueue q(5);
    q.print();

    q.push(11);
    q.print();
    
    q.push(12);
    q.print();

    q.push(13);
    q.print();

    q.push(14);
    q.print();

    q.push(15);
    q.print();

    q.push(16);

    q.pop();
    q.pop();
    q.pop();
    q.print();

    q.push(100);
    q.print();
    q.push(200);
    q.print();
    q.push(300);
    q.print();
    q.push(400);
    q.print();


    return 0;
}