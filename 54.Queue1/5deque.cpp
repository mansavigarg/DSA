#include<iostream>
using namespace std;

//! Normal deque
class Deque{
    public:
        int *arr;
        int size;
        int front;
        int rear;

    Deque(int size){
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push_back(int val){
        //# OverFlow case
        if(rear == size - 1){
            cout << "OverFlow" << endl;
        }
        else if(front == -1 && rear == -1){
        //# Empty case-> single element insert
            front++;
            rear++;
            arr[rear] = val;
        }
        else{
        //# Normal Case
            rear++;
            arr[rear] = val;
        }
    }

    void push_front(int val){
        //# OverFlow case
        if(front == 0){
            cout << "OverFlow" << endl;
        }
        else if(front == -1 && rear == -1){
        //# Empty case-> single element insert
            front++;
            rear++;
            arr[front] = val;
        }
        else{
            //# Normal Case
            front--;
            arr[front] = val;
        }
    }

    void pop_front(){
        //# UnderFlow
        if(front == -1 && rear == -1){
            cout << "Queue UnderFlow" << endl;
            return;
        }
        else if(front == rear){
        //# single element case
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else{
        //# normal case
            arr[front] = -1;
            front++;
        }
    }

    void pop_back(){
        //# UnderFlow
        if(front == -1 && rear == -1){
            cout << "UnderFlow" << endl;
        }
        else if(front == rear){
        //# Single element pop
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        else{
        //# Normal case
            arr[rear] = -1;
            rear--;
        }
    }
};


//! CIRCULAR deque
class CDeque{
    public:
        int *arr;
        int size;
        int front;
        int rear;

    CDeque(int size){
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push_back(int val){
        //# OverFlow Condition
        if((front == 0 && rear == size-1) || (rear == front - 1)){
            cout << "OverFlow, Queue is full." << endl;
            return;
        } 
        else if(front == -1 && rear == -1){
        //# empty case
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
        //# normal case
            rear++;
            arr[rear] = val;
        }
    }

    void push_front(int val){
        //# OverFlow case
        if((front == 0 && rear == size-1) || (rear == front - 1)){
            cout << "OverFlow, Queue is full." << endl;
            return;
        } 
        else if(front == -1 && rear == -1){
        //# Empty case-> single element insert
            front++;
            rear++;
            arr[front] = val;
        }
        else if(front == 0 && rear != size - 1){
        //# Circular Nature
            front = size - 1;
            arr[front] = val;
        }
        else{
            //# Normal Case
            front--;
            arr[front] = val;
        }
    }

    void pop_front(){
        //# UnderFlow
        if(front == -1 && rear == -1){
            cout << "Queue UnderFlow" << endl;
            return;
        }
        else if(front == rear){
        //# single element case
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
        //# normal case
            arr[front] = -1;
            front++;
        }
    }

    void pop_back(){
        //# UnderFlow
        if(front == -1 && rear == -1){
            cout << "Queue UnderFlow" << endl;
            return;
        }
        else if(front == rear){
        //# Single element pop
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        else if(rear == 0){
        //# Circular case
        arr[rear] = -1;
        rear = size -1;
        }
        else{
        //# Normal case
            arr[rear] = -1;
            rear--;
        }
    }
};

int main(){
    
    return 0;
}