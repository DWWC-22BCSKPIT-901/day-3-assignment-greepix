#include <iostream>
#include <string>
using namespace std;

void reverseString(const string &str, int index) {
    if (index < 0) 
        return;
    
    cout << str[index]; 
    reverseString(str, index - 1); 
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Reversed string: ";
    reverseString(str, str.length() - 1);
    cout << endl;

    return 0;
}
