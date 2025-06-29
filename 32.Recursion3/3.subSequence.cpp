#include<iostream>
using namespace std;

void findSubsequence(string str, string output, int index){
    // base case
    if(index >= str.length()){
        //$ is case mein ans jo hai vo build ho chuka hai string output mein as last index pr jate hai sb combination ban gaye hai -- refer notes here for diagram
        cout << output << endl;
        return;
    }

    char ch = str[index];

    // //* Exclude ch character
    // findSubsequence(str, output, index+1);
    // //* Include ch character
    // //*  output string mein ch character ko include krdo
    // output.push_back(ch);
    // findSubsequence(str,output,index+1);


    //# agar include upr rakh rhe hai and exclude niche rakh rhe hai 
    //@ Include ch character
    output.push_back(ch);
    findSubsequence(str,output,index+1);
    //@ Exclude ch character
    output.pop_back();
    findSubsequence(str,output,index+1);

} 


int main(){
    string str = "MANSAVI";
    string output = "";
    int index = 0;

    findSubsequence(str,output,index);
    return 0;
}