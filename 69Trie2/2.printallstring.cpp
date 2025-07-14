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


void deleteWord(TrieNode* root, string word){
    if(word.length() == 0){
        root->isTerminal = false;
    }

    // 1 case mera
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL){
        // present 
        child = root->children[index];
    }else {
        return;
    }
    // baki recursion
    deleteWord(child, word.substr(1));
}

void storeString(TrieNode* root, vector<string>& ans, string &input, string &prefix){
    // base case
    if(root->isTerminal){
        // ans store
        ans.push_back(prefix + input);
        // return -> yha se return isslye ni kiya kyokki beacase jha khade hai hm usse char k niche bi to or char ho sakte hai na  
    }

    for(char ch = 'a'; ch <= 'z'; ch++){
        int index = ch - 'a';
        TrieNode* next = root->children[index];
        if(next != NULL){
            // child exist krta hai
            input.push_back(ch);

            // baki recursion
            storeString(next, ans, input, prefix);
            // backtrack
            input.pop_back();
        }
    }
}

void findPrefixString(TrieNode* root, string input, vector<string> &ans, string &prefix){
    // Base case
     if(input.length() == 0){
        TrieNode* lastchar = root;
        storeString(lastchar, ans, input, prefix);
        return;
     }
     char ch = input[0];
     int index = ch - 'a';
     TrieNode* child;
     if(root->children[index] != NULL){
        // child present
         child = root->children[index];
     }else{
        return;
     }
     // recursive call
     findPrefixString(child, input.substr(1), ans, prefix);
}


vector<vector<string>> getSuggestions(TrieNode* root, string input){

    vector<vector<string>> output;
    TrieNode* prev = root;
    string inputHelper = "";
    for(int i = 0; i < input.length(); i++){
        char lastChar = input[i];
        int index = lastChar - 'a';
        TrieNode* curr = prev->children[index];
        if(curr == NULL){
            break;
        }else{
            vector<string> nicheKaAns;
            inputHelper.push_back(lastChar);
            string dummy = "";
            storeString(curr, nicheKaAns, inputHelper, dummy);
            output.push_back(nicheKaAns);
            prev = curr;
        }
    }
    return output;
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

    /*
        given input -> jokr
        find all string with
                        ->j
                        ->jo
                        ->jok
                        ->jokr
    */


    vector<vector<string>> ans = getSuggestions(root, "loa");

    for(int i = 0; i < ans.size(); i++){
        cout << i << " -> ";
        for(auto str : ans[i]){
            cout << str << " ";
        }
        cout << endl;
    }


    // string input = "l";
    // string prefix = input;
    // vector<string> ans;

    // findPrefixString(root, input, ans, prefix);

    // for(auto i : ans){
    //     cout << i << " ";
    // }
    // cout << endl;



    return 0;
}