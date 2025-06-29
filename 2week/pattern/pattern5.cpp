#include <iostream>
using namespace std;

int main() {
    
    int n;
    cout << "Enter the value of n: " ;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << i;
    }
    cout << endl;

    // Subsequent rows
    for (int i = 2; i <= n; i++) {
        cout << i; // Print the first number
        for (int j = 0; j < n - i - 1; j++) {
            cout << " "; // Print spaces
        }
        
        // Only print the last number in the last column if it's not the last row
        if (i != n) {
            cout << n; // Print the last number in the row
        }
        
        cout << endl;
    }

    return 0;
}
