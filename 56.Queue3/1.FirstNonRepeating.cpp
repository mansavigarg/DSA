#include<iostream>
using namespace std;

int main(){
    string str = "ababc";

    queue<char> q;

    int freq[26] = {0};

    for(int i = 0; i < str.length(); i++){
        char ch = str[i];
        freq[ch - 'a']++;
        q.push(ch);

        // ans find out kro
        while(!q.empty()){
            char frontCharacter = q.front();
            if(freq[frontCharacter-'a'] > 1){
                // yani y answer ni hai
                q.pop();
            }else{
                // means freq == 1 wala case
                // yahi ans hai
                cout << frontCharacter << "->";
                break;
            }
        }

        // yha tk aaye mtlb koi ans ni mila means # is ans
        if(q.empty()){
            cout << "#" << "->";
        }
    }
    cout << endl;
    return 0;
}