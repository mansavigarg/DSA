#include<iostream>
using namespace std;

int main(){
    //! Creation
    queue<int> q;

    //! Insertion
    q.push(5);
 
    //! Size
    cout << "Size of Queue is: " << q.size() << endl;

    //! Empty
    if(q.empty()){
        cout << "Queue is Empty" << endl;
    }else{
        cout << "Queue is not Empty" << endl;
    }

    //! Remove
    q.pop();

    //! Size
    cout << "Size of Queue is: " << q.size() << endl;

    //! Empty
    if(q.empty()){
        cout << "Queue is Empty" << endl;
    }else{
        cout << "Queue is not Empty" << endl;
    }

    q.push(5);
    q.push(15);
    q.push(25);
    q.push(35);

    //! Front Element
    cout << "Front Element is: " << q.front() << endl;

    //! Rear Element
    cout << "Rear Element is: " << q.back() << endl;
    return 0;
}