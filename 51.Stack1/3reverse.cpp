#include<iostream>
using namespace std;

int main(){
    string str = "Shivani";
    stack<char> st;

    for(int i = 0;i < str.length(); i++ ){
        st.push(str[i]);
    }

    while( !st.empty() ){
        cout << st.top();
        st.pop();
    }
    cout << endl;
    return 0;
}