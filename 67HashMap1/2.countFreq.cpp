#include<iostream>
using namespace std;

void countCharacter(unordered_map<char, int> &mapping, string str){
    for(auto i : str){
        char ch = i;
        mapping[ch]++;
    }
}

int main(){
    string str = "shivanisoni";
    unordered_map<char, int> mapping;
    countCharacter(mapping, str);

    // for(auto i : str){
    //     char ch = i;
    //     mapping[ch]++;
    // }


    for(auto i : mapping){
        cout << i.first << " -> "  << i.second << endl;
    }
    return 0;
}