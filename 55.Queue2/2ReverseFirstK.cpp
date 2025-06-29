#include<iostream>
using namespace std;

void reverseFirstK(queue<int> &q, int k) {
    // code here
    int n = q.size();
    stack<int> s;
    
    if( k > n || k == 0){
        return ;
    }
    
    //Pushing first k elements in the stack
    for(int i = 0; i < k; i++){
        s.push(q.front());
        q.pop();
    }
    
    // Pushing elements baack to queue
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    
    // pop and push the first n-k elements at the back of the queue
    for(int i = 0; i < n-k; i++){
        int temp = q.front();
        q.pop();
        q.push(temp);
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

     reverseFirstK(q,4);

     cout << "Printing queue: ";
     while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
     }
     cout << endl;
    return 0;
}