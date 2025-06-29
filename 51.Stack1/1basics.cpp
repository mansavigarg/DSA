#include<iostream>
using namespace std;

int main(){
    // creation
    stack<int> st;

    // insertion
    st.push(12);
    st.push(22);
    st.push(32);

    // size check
    cout << "Size of stack : " << st.size() << endl;

    // remove
    st.pop();
    cout << "Size of stack : " << st.size() << endl;

    // check empty
    if(st.empty()){
        cout << "Yes empty" << endl;
    }else{
        cout << "Not empty" << endl;
    }

    // top element
    cout << "Top element: " << st.top() << endl;
    return 0;
}