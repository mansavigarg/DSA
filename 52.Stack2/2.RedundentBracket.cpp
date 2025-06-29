#include<iostream>
using namespace std;

bool checkRedundent(string &str){
    stack<char> st;

    for(int i = 0; i < str.length(); i++){
        char ch = str[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else if ( ch == ')'){
            int operatorCount = 0;
            while( !st.empty() &&  st.top() != '('){
                char temp = st.top();
                if(temp == '+' || temp == '-' || temp == '*' || temp == '/'){
                    operatorCount++;
                }
                st.pop();
            }
            // yha aap tbi paunchoge if top pr opening bracket hoga
            st.pop();

            if(operatorCount == 0){
                return true;
            }

        }
    }
    // agar mein yha tk paucha hu 
    // means har ek bracket k pair k  beech mein ek operator paka hoga
    return false;
}

int main(){
    string str = "((a+b)*((c)+d))";
    bool ans = checkRedundent(str);
    if(ans){
        cout << "present" << endl;
    }else cout << "Not Present" << endl;
    return 0;
}