#include<iostream>
using namespace std;

void print(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
void printvv(vector<vector<int>> &v){
    for(int i = 0; i < v.size(); i++){
        vector<int>&temp = v[i];
        int a = temp[0];
        int b = temp[1];
        cout << a << " " << b << endl;
    }
    cout << endl;
}

bool mycompFor1stIndex(vector<int> &a, vector<int> &b){
    // return a[0] < b[0]; // this is by default of 0th index
    return a[1] < b[1];
}

int main(){
    vector<vector<int>> v;
    cout << "Enter Size " << endl;
    int n;
    cin >> n;
    for(int i = 0; i<n;  i++){
        int a , b;
        cout << "Enter a and b " << endl;
        cin >> a >> b;

        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        v.push_back(temp);
    }

    cout << "Here are the values: " << endl;
    printvv(v);
    cout << "Here are the Sorted values: " << endl;
    sort(v.begin(), v.end(), mycompFor1stIndex);
    printvv(v);

    return 0;
}