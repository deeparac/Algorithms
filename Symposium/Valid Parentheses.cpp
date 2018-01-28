class Solution {
public:
    /*
     * @param s: A string
     * @return: whether the string is a valid parentheses
     */
    bool isValidParentheses(string &s) {
        // write your code here
        stack<char> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '[' || s[i] == '{' || s[i] =='(') {
                stk.push(s[i]);
            } else if (s[i] == ']' || s[i] == '}' || s[i] ==')') {
                if (stk.empty()) {
                    return false;
                }

                char leftPar = stk.top();
                switch (leftPar) {
                    case '[': if (s[i] != ']') return false; break;
                    case '{': if (s[i] != '}') return false; break;
                    case '(': if (s[i] != ')') return false; break;
                    default: break;
                }

                stk.pop();
            } else {
                throw std::invalid_argument( "received invalid string" );
            }
        }

        return stk.empty();
    }
};
