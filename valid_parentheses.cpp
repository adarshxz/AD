#include <iostream>
#include <stack>
#include <string>
#include <vector>

// Checks whether brackets in an expression are balanced
// Supports (), {}, and []
bool isValidParentheses(const std::string& s) {
    std::stack<char> st;

    for (char ch : s) {
        // Push opening brackets onto stack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        // Check closing brackets against top of stack
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty()) {
                return false; // Closing bracket with no matching opening bracket
            }

            char top = st.top();
            st.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false; // Mismatched bracket type
            }
        }
    }

    // Valid only if all opened brackets were closed
    return st.empty();
}

int main() {
    std::cout << "--- Balanced Parentheses Checker in C++ ---\n\n";

    std::vector<std::string> testExpressions = {
        "()",
        "()[]{}",
        "(]",
        "([)]",
        "{[]}",
        "((1 + 2) * [3 / {4 - 5}])",
        "((()",
        ")("
    };

    for (const auto& expr : testExpressions) {
        bool balanced = isValidParentheses(expr);
        std::cout << "Expression: " << expr << "\n";
        std::cout << "Status    : " << (balanced ? "Balanced [VALID]" : "Unbalanced [INVALID]") << "\n\n";
    }

    return 0;
}
