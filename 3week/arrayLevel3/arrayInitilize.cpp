#include<iostream>
using namespace std;


void printArray(int arr[][4],int row,int col){
    for(int i = 0; i < row ; i++){
        for(int j = 0; j < col; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


void colWisePrint(int arr[][4], int row, int col ){
  for(int i=0; i<col; i++) {
    for(int j=0; j<row; j++) {
      cout << arr[j][i] << " ";
    }
    cout << endl;
  }
}


int main(){
//create a 2D array 
//   int arr[3][3];


//iniitialse
//   int arr[3][4] = {
//   {1,2,3,4},
//   {5,6,7,8},
//   {9,10,1,11}
//   };

  int brr[] = {1,2,3,4};

  int crr[][4] = {
  {1,2,3,4},
  {5,6,7,8},
  {9,10,1,11}
  };

  int drr[][4] = {
  {1,2,3,4},
  {5,6,7,8},
  {9,10,1,11}
  };

  int arr[3][4] = {
         {1,2,3,4},
         {5,6,7,8},
         {9,10,11,12}
    };

    // int row = 3;
    // int col = 4;
    // printArray(arr,row,col);
    // colWisePrint(arr,  row,  col);

    // taking  input in an array
    int zrr[3][3];
    int row = 3;
    int col = 3;

    for(int i=0; i<row; i++) {
    for(int j=0; j<col; j++) {
        cout << "Enter the input for row index: " << i << " column index: " << j << endl;
        cin >> zrr[i][j] ;
    }
    }


    return 0;
}