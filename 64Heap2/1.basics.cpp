#include<iostream>
using namespace std;

int main(){
    //! create max-heap
    priority_queue<int> pq;

    //! Insertion
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);

    cout << "Top Element of Heap: " << pq.top() << endl;
    pq.pop();
    cout << "Top Element of Heap: " << pq.top() << endl;
    cout << "Size: " << pq.size() << endl;

    cout << endl << endl;

    //! create min-heap
    priority_queue<int, vector<int>, greater<int> > q;
    q.push(10);
    q.push(20);
    q.push(40);
    q.push(50);

    cout << "Top Element of min-Heap: " << q.top() << endl;
    q.pop();
    cout << "Top Element of min-Heap: " << q.top() << endl;
    cout << "Size: " << q.size() << endl;

    return 0;
}