#include<iostream>
using namespace std;

void rearrangeQueue(queue<int> &q1) {
    // code here
    queue<int> q2;
    int size = q1.size();
    
    // inserting first half in the q2
    for(int i = 0; i < size/2; i++){
        q2.push(q1.front());
        q1.pop();
    }
    
    // now merging both the queues in the original queue q1
    for(int i = 0; i < size/2; i++){
        q1.push(q2.front());
        q2.pop();
        
        q1.push(q1.front());
        q1.pop();
    }
}

int main(){
     queue<int> q;

     q.push(11);
     q.push(12);
     q.push(13);
     q.push(14);
     q.push(15);
     q.push(16);

     rearrangeQueue(q);

     cout << "Printing queue: ";
     while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
     }
     cout << endl;
    return 0;
}