#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int basicCalculator(string s) {
    stack<int> stk;
    int num = 0;
    int result = 0;
    int sign = 1;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }

        if (c == '+' || c == '-' || c == '*' || c == '/' || i == s.size() - 1) {
            if (c == '+' || c == '-') {
                result += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
            } else if (c == '*' || c == '/') {
                if (c == '*') {
                    num = stk.top() * num;
                } else if (c == '/') {
                    num = stk.top() / num;
                }
                stk.pop();
            }

            if (c != '*' && c != '/' && c != ' ') {
                stk.push(num);
            }
        }
        if (c == ')' || i == s.size() - 1) {
            result += sign * num;
        }
    }
    
    return result;
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);  
    
    cout << "Result: " << basicCalculator(expression) << endl;
    return 0;
}