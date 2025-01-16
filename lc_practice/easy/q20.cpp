#include <stack>
#include <string>

// Use stack, iterate through string, if bracket open push, else check if character is 

class Solution {
public:
    bool isValid(const std::string& s) {
        std::stack<char> stk;
        
        for (const auto& c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } 
            else {
                if (stk.empty()) {
                    return false;
                }
                
                const auto top = stk.top();
                if ((c == ')' && top == '(') || 
                    (c == '}' && top == '{') || 
                    (c == ']' && top == '[')) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        
        return stk.empty();
    }
};
