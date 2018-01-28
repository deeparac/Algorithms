class Solution {
public:
    /*
     * @param str: A string
     * @return: An integer
     */
    int atoi(string &str) {
        // write your code here
        int sign = 1; // 1 for +, -1 for -
        int rst = 0;
        int idx = 0;

        // trim
        while (idx < str.size() && str[idx] == ' ') {
            idx += 1;
        }

        // sign
        if (idx < str.size() && str[idx] == '+' || str[idx] == '-') {
            sign = str[idx] == '+' ? 1 : -1;
            idx += 1;
        }

        // number
        while (idx < str.size()) {
            if (str[idx] == '.') {
                return sign * rst;
            }

            if (!isdigit(str[idx])) {
                return sign * rst;
            }

            int cur = str[idx] - '0';
            if (rst > INT_MAX / 10 || (rst == INT_MAX / 10 && cur > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            rst = rst * 10 + cur;
            idx += 1;
        }

        return sign * rst;
    }
};
