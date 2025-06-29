#include <iostream>
using namespace std;

int main()
{
    try
    {
        int *p = new int[1000000000000000000];
        cout << "Memory allocation is successfully\n";
        delete[] p;
    }
    catch (const exception &e)
    {
        cout << "Exception occurred: " << e.what() << endl;
    }

    return 0;
}