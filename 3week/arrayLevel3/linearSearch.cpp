#include<iostream>
using namespace std;


bool findTarget(int arr[][4], int row, int col, int target){
    for(int i = 0; i<row; i++){
        for (int j=0; j<col; j++){
            if(arr[i][j] == target){
                return true;
            }
        }
    }
    //iss line pr tabhi aa skte ho,
    //jab saare k saare elements check
    //ho chuke honge and target nahi mila hoga
    //return krdo false;    
    return false;
}
int main(){
    int arr[4][4] = {
            {1,2,3,4},
            {5,6,70,8},
            {9,10,1,11},
            {12,24,46,89}
            };
    int row = 4;
    int col = 4;
    int target = 43;

    cout << "Found or Not: " << findTarget(arr, row, col, target) << endl;
    return 0;
}