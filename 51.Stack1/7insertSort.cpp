#include<iostream>
using namespace std;

void inserSorted(stack<int> &st, int element){

    // base case and remember this is important as wee need to check if the stack is empty or not before accessing the top element of the stack
    if( st.empty() || element > st.top()){
        st.push(element);
        return; 
    }

    // 1 case khud kro
    int temp = st.top();
    st.pop();

    // baki recursion
    inserSorted(st,element);

    // backtracking
    st.push(temp);
}

int main(){
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    int element = 25;

    inserSorted(st,element);

    while( !st.empty() ){
        cout << st.top() << " ";
        st.pop();
    }


    return 0;
}