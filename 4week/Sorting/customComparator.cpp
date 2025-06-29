#include<iostream>
using namespace std;

void print(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

bool mycomp(int &a, int &b){
    // return a < b; // increasing order sort
    return a > b; // decreasing order sort
}

int main(){
    vector<int> v = {54,22,5,67,95,245};
    cout << "Increasing Order sort: " ;
    sort(v.begin(), v.end());
    print(v);

    cout << "Decreasing Order sort: " ;
    sort(v.begin(), v.end(), mycomp);
    print(v);

    return 0;
}