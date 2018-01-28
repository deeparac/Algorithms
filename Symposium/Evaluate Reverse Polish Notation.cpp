class Solution {
public:
    /*
     * @param tokens: The Reverse Polish Notation
     * @return: the value
     */
    int evalRPN(vector<string> &tokens) {
        // write your code here
        stack<string> stk;
        for (auto& token : tokens) {
            // cout << token << " " << stk.size() << endl;
            if (token.size() == 1 && isdigit(token[0]) ||
                token.size() >= 2) {
                stk.push(token);
            } else if (token.size() == 1 && string("+-*/").find(token) != string::npos) {
                int right = stoi(stk.top()); stk.pop();
                int left = stoi(stk.top()); stk.pop();

                switch (token[0]) {
                    case '+': stk.push(to_string(left + right)); break;
                    case '-': stk.push(to_string(left - right)); break;
                    case '*': stk.push(to_string(left * right)); break;
                    case '/': stk.push(to_string(left / right)); break;
                    default: break;
                }
            }
        }

        if (stk.size() != 1) {
            throw std::invalid_argument("Invalid input string");
        }

        return stoi(stk.top());
    }
};
