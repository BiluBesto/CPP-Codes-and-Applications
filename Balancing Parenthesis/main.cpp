#include <iostream>
#include <string>
using namespace std;

int top = -1;

bool isEmpty() {
    return top == -1;
}

void push(char arr[], char val) {
    arr[++top] = val;
}

void pop(char arr[]) {
    top--;
}

int main() {
    string s;
    cout << "Enter balancing parenthesis expression: ";
    cin >> s;

    char* sarr = new char[s.length()];
    bool valid = true;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            push(sarr, c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty())
                {
                    valid = false; break;
            }

            if (c == ')' && sarr[top] == '(')
                pop(sarr);
            else if (c == ']' && sarr[top] == '[')
                pop(sarr);
            else if (c == '}' && sarr[top] == '{')
                pop(sarr);
            else {
                valid = false;
                break;
            }
        }
        else {
            cout << "Invalid Expression!\n";
            delete[] sarr;
            return 0;
        }
    }

    if (valid && isEmpty())
        cout << "The given expression is a valid balancing parenthesis\n";
    else
        cout << "The given expression is NOT a valid balancing parenthesis\n";
}
