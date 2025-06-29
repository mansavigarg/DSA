#include<iostream>
using namespace std;

void rowWiseSum(int arr[][4], int row, int col){
    for(int i=0; i<row; i++){
        int sum = 0;
        for(int j=0; j<col; j++){
            sum = sum + arr[i][j];
        }
        cout << "sum of row " << i << " is: " << sum << endl;
    }
}
void colWiseSum(int arr[][4], int row, int col){
    for(int i=0; i<col; i++){
        int sum = 0;
        for(int j=0; j<row; j++){
            sum = sum + arr[j][i];
        }
        cout << "sum of col " << i << " is: " << sum << endl;
    }
}

void diagonalPrint(int arr[][4], int row, int col){
    for (int i = 0; i<row; i++){
        cout << arr[i][i] << endl;
    }
}
void diagonalPrintOpposite(int arr[][4], int row, int col){
    for (int i = 0; i<row; i++){
        cout << arr[i][row-i-1] << endl;
    }
}
int diagonalSum(int arr[][4], int row, int col){
    int sum = 0;
    for (int i = 0; i<row; i++){
        sum = sum + arr[i][i];
    }
    return sum;
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

    cout << "Printing row wise sum" << endl;
        rowWiseSum(arr,row,col);
    cout << "Printing col wise sum" << endl;
        colWiseSum(arr,row,col);
    cout << "Printing Diagonal " << endl;
        diagonalPrint(arr,row,col);
    cout << "Printing Diagonal but opposite" << endl;
        diagonalPrintOpposite(arr,row,col);
    cout << "Diagonal sum is: " ;
    cout << diagonalSum(arr,row,col) << endl;

    
    return 0;
}