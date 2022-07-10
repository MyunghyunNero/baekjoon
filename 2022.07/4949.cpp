
#include <iostream>
#include <string>
#include <stack>
using namespace std;
 
int main() {
    while (true) {
        string str;
        getline(cin, str);
        if (str == ".") {
            break;
        }
        stack<char> s;
        bool flag = false;
        int len=str.length();
        for (int i = 0; i < len; i++) {
            char c = str[i];
                
            if ((c == '(') || (c == '[')) {
                s.push(c);
            }
            else if (c == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                }
                else {
                    flag = true;
                    break;
                }
            }
            else if (c == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                }
                else {
                    flag = true;
                    break;
                }
            }
        }
        if (flag==false && s.empty()) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
}
