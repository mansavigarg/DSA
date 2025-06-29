#include<iostream>
using namespace std;

void insertAtBottom(stack<int> &st, int element){
    if(st.empty()){
        st.push(element);
        return;
    }

    // 1 case khud krna hai 
    int temp = st.top();
    st.pop();

    //baki recursion
    insertAtBottom(st,element);

    // backtraking
    st.push(temp);
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    int element = 400;

    insertAtBottom(st,element);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    
    return 0;
}