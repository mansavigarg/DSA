#include<iostream>
using namespace std;

int findDivide(int divisor,int divident){
    int s = 0;
    int e = divident;
    int ans = -1;

    while ( s <= e){
        int mid = s + (e-s) / 2;

        if(divisor*mid <= divident){
            ans = mid;
            s = mid + 1;
        }
        else if (divisor*mid >= divident){
            e = mid - 1;
        }
    }
    return ans;

}

int main(){
    int divisor = -4;
    int divident = 35;
    
    int ans = findDivide(abs(divisor),abs(divident));

    if(((divisor > 0) && (divident < 0)) || ((divisor < 0) && (divident > 0))){
        ans = 0 - ans;
    }

    cout << "Final ans is: " << ans << endl;

    
    return 0;
}
