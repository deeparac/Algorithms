class Solution {
public:
    /*
     * @param s: an expression includes numbers, letters and brackets
     * @return: a string
     */
    string expressionExpand(string &s) {
        // write your code here
        stack<char> cstk; // main stack
        stack<int>  nstk; // record numbers of repeats
        stack<char> rstk; // side stack

        int times = 0; // count repeats

        for (auto c : s) {
            if (isdigit(c)) {
                times *= 10;
                times += c - '0';
            } else if (c == '[') {
                nstk.push(times);
                times = 0;

                cstk.push(c);
            } else if (c == ']') {
                // init
                string new_str = "";
                stack<char> buffer;

                // process
                while (!cstk.empty() && cstk.top() != '[') {
                    buffer.push(cstk.top()); cstk.pop();
                }
                if (!cstk.empty() && cstk.top() == '[') {
                    cstk.pop();
                }

                while (!buffer.empty()) {
                    new_str += buffer.top(); buffer.pop();
                }

                int t = nstk.top(); nstk.pop();
                for (int j = 0; j < t; ++j) {
                    for (int k = 0; k < new_str.size(); ++k) {
                        cstk.push(new_str[k]);
                    }
                }
            } else {
                cstk.push(c);
            }
        }

        while (!cstk.empty()) {
            rstk.push(cstk.top()); cstk.pop();
        }

        string rst = "";
        while (!rstk.empty()) {
            rst += rstk.top(); rstk.pop();
        }

        return rst;
    }
};
