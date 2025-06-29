#include<iostream>
using namespace std;

void insertAtBottom(stack<int> &st, int element){
    if(st.empty()){
        st.push(element);
        return;
    }
    int temp = st.top();
    st.pop();
    insertAtBottom(st,element);
    st.push(temp);
}

void reverseStack(stack<int> &st){
    // base case
    if( st.empty() ){
        return;
    }

    // 1 Case khud solve kro 
    int temp = st.top();
    st.pop();

    // recursion
    reverseStack(st);

    // Backtracking
    insertAtBottom(st,temp);
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    int element = 400;

    reverseStack(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    
    return 0;
}