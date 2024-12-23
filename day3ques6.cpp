#include <iostream>
using namespace std;

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) 
        return 1;
    return n * factorial(n - 1); 
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n < 0)
        cout << "Factorial is not defined for negative numbers." << endl;
    else
        cout << n << "! = " << factorial(n) << endl;

    return 0;
}
