#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <cmath>
#include <climits>

void p(const std::string& s) {
    std::cout << s << std::endl;
}

void p(const std::list<char>& s) {
    for (char c : s) {
        std::cout << c << ' ';
    }
    std::cout << std::endl;
}

void p(const char& s) {
    std::cout << s << std::endl;
}

std::list<char> sya(const std::string& exp) {
    std::list<char> output;
    std::list<char> stack;
    std::map<char, int> op;
    op['+'] = 10;
    op['-'] = 10;
    op['*'] = 20;
    op['/'] = 20;
    op['^'] = 30;

    for (char const& c : exp) {
        if (std::isdigit(c)) {
            output.push_back(c);
            continue;
        }
        if (!stack.empty()) {
            if (op[stack.front()] >= op[c]) {
                output.push_back(stack.front());
                stack.pop_back();
                stack.push_back(c);
            }
            else if (op[stack.front()] < op[c]) {
                stack.push_back(c);
            }
            continue;
        }
        stack.push_back(c);
    }
    for (auto it = stack.begin(); it != stack.end(); it++) {
        output.push_back(*it);
    }
    return output;
}


std::string list_to_string(const std::list<char>& vec) {
    std::string output;
    for (auto i : vec) {
        output += i;
    }
    return output;
}

float scanNum(char ch) {
    int value;
    value = ch;
    return float(value - '0');
}

bool isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return true;
    return false;
}

float operation(int a, int b, char op) {
    switch (op)
    {
    case '+':
        return b + a;
    case '-':
        return b - a;
    case '*':
        return b * a;
    case '/':
        return b / a;
    case '^':
        return pow(b, a);
    default:
        return INT_MIN;
    }
}

std::stack<char> string_to_stack(const std::string& str) {
    std::stack<char> a;
    for (char c : str) {
        a.push(c);
    }
    return a;
}

float convert(const std::string& str) {
    int a;
    int b;
    std::stack<char> stk = string_to_stack(str);

    for (auto it = str.begin(); it != str.end(); it++) {
        if (isOperator(*it)) {
            a = stk.top();
            stk.pop();
            b = stk.top();
            stk.pop();
            stk.push(operation(a, b, *it));
        }
        else if (std::isdigit(*it)) {
            stk.push(scanNum(*it));
        }
    } 
    return stk.top();
}

int main() {

    std::string str = "7*4/2+6";

    std::cout << "Original Equation : " << str << std::endl;

    std::list<char> a = sya(str);

    std::cout << "Polish Notation: ";

    for (auto i : a) {
        std::cout << i << ' ';
    }

    std::cout << std::endl;

    std::cout << "Solved Equation: " << convert(list_to_string(a)) << std::endl;

    return 0;

}





