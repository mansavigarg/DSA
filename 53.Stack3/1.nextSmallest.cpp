#include<iostream>
using namespace std;

vector<int> nextSmallestElement(int *arr, int size, vector<int> &ans){
    stack<int> st;
    st.push(-1);
    
    // for loop from right to left and storing the mini in the stack
    for(int i = size - 1; i >= 0; i--){
        int curr = arr[i];

        // ans ko find kro current k lye
        while(st.top() >= curr){
            st.pop();
        }
        ans[i] = st.top();

        st.push(curr);
    }
    return ans;
}

int main(){
    int arr[5] = {8,4,6,2,3};
    int size = 5;
    vector<int> ans(size);

    ans = nextSmallestElement(arr,size,ans);

    for(auto i : ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}