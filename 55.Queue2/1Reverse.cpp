#include<iostream>
using namespace std;

//# Using Stack 
void reverseQueue(queue<int> &q){
    stack<int> s;

    // Queue k element one by one stack mein daal do
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    // Stack se elements Queue mein vapis daal do
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

//# Using Recursion
void reverse(queue<int> &q){
    // Base case
    if(q.empty()){
        return;
    }

    int element = q.front();
    q.pop();

    reverse(q);

    q.push(element);
}

int main(){
     queue<int> q;

     q.push(11);
     q.push(12);
     q.push(13);
     q.push(14);
     q.push(15);
     q.push(16);

     reverse(q);

     cout << "Printing queue: ";
     while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
     }
     cout << endl;
    return 0;
}