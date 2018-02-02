class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c : s) {
            if (c == '(' || c =='[' || c == '{') {
                stk.push(c);
            } else {
                if (stk.empty()) {
                    return false;
                }
                char cc = stk.top(); stk.pop();
                if (c == ')') {
                    if (cc != '(') {
                        return false;
                    }
                } else if (c == ']') {
                    if (cc != '[') {
                        return false;
                    }
                } else if (c == '}') {
                    if (cc != '{') {
                        return false;
                    }
                }
            }
        }
        return stk.empty();
    }
};
