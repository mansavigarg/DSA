#include<iostream>
using namespace std;

void inserSorted(stack<int> &st, int element){
    if( st.empty() || element > st.top()){
        st.push(element);
        return; 
    }
    int temp = st.top();
    st.pop();
    inserSorted(st,element);
    st.push(temp);
}

void sortStack(stack<int> &st){
    // base case
    if(st.empty()){
        return;
    }
    // 1 case 
    int temp = st.top();
    st.pop();
    // recursion
    sortStack(st);
    // backtracking
    inserSorted(st,temp);
}

int main(){
    stack<int> st;

    st.push(10);
    st.push(4);
    st.push(6);
    st.push(1);
    st.push(22);
    st.push(0);

    sortStack(st);


    while( !st.empty() ){
        cout << st.top() << " ";
        st.pop();
    }


    return 0;
}