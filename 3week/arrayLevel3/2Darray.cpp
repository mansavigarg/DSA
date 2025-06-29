#include<iostream>
using namespace std;

int main(){
    // 2D array
    vector< vector<int> > arr(5, vector<int>(10,-1));
    // in 2d vector : row size -> arr.size()
    // and col size -> arr[i].size()
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size();j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Jagged Array

    // declaring 2d vector of name brr
    vector < vector<int> > brr ;

    // vectors of different lenght
    vector<int> vec1(10,1);
    vector<int> vec2(2,2);
    vector<int> vec3(8,3);
    vector<int> vec4(3,4);
    vector<int> vec5(9,5);

    // pushing these in brr
    brr.push_back(vec1);
    brr.push_back(vec2);
    brr.push_back(vec3);
    brr.push_back(vec4);
    brr.push_back(vec5);

    for(int i=0; i<brr.size(); i++){
        for(int j=0; j<brr[i].size();j++){
            cout << brr[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}