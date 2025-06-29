#include<iostream>
using namespace std;

void solve(stack<int> &st, int &pos, int &ans){
    // base case
    if(pos == 1){
        ans = st.top();
        return;
    }
 
    // 1 case hm kr rhe hai 
    pos--;
    int temp = st.top();
    st.pop();

    // recursion
    solve(st,pos,ans);

    // backtracking
    st.push(temp);
}

int getMiddleElement(stack<int> &st){
    int size = st.size();
    if(st.empty()){
        return -1;
    }else {
        // stack is not empty
        // odd
        int pos = 0;
        if(size & 1){
            pos = size/2 + 1;
        }else{
            // even ka case
            pos = size/2;
        }

        int ans = -1; 
        solve(st, pos, ans);
        return ans;
    }
    
}

int main(){
    stack<int> st;

    st.push(11);
    st.push(12);
    st.push(13);
    st.push(14);
    st.push(15);

    int mid = getMiddleElement(st);

    cout << "Middle Element is " << mid << endl;
    return 0;
}