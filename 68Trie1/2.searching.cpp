#include<iostream>
using namespace std;

class TrieNode{
    public:
        char value;
        TrieNode* children[26];
        bool isTerminal;

    TrieNode(char val){
        this->value = val;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};


// insertion
void insertWord(TrieNode* root, string word){
    // base case
    if(word.length() == 0){
        root->isTerminal = true;
        return; 
    }

    char ch = tolower(word[0]);
    int index = ch - 'a';
    TrieNode* child;
    if(root->children[index] != NULL){
        // present hai child
        child = root->children[index];
    }
    else{
        // absent 
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    insertWord(child, word.substr(1));
}


bool searchWord(TrieNode* root, string word){
    // Base case
    if( word.length() == 0 ){
        return root->isTerminal;
    }

    char ch = tolower(word[0]);
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL){
        // present hai child
        child = root->children[index];
    }else {
        return false;
    }

    // baki recursion
    return searchWord(child, word.substr(1));
}

int main(){
    TrieNode* root = new TrieNode('-');

    insertWord(root, "cater");
    insertWord(root, "care");
    insertWord(root, "com");
    insertWord(root, "lover");
    insertWord(root, "loved");
    insertWord(root, "load");
    insertWord(root, "lov");
    insertWord(root, "cat");
    insertWord(root, "bat");
    insertWord(root, "car");


    cout << "Insertion Done" << endl;

    

    if(searchWord(root, "lov")) cout << "Found" << endl;
    else cout << "Not Found" << endl;
     
    return 0;
}


// TC: generally is O(1) or it is directly prop to the lenght of the string to be inserted