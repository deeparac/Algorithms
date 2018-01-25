class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        // write your code here
        string rst = "";
        for (string& str : strs) {
            int len = str.size();
            rst = rst + to_string(len) + "#" + str;
        }
        cout << rst << endl;
        return rst;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        // write your code here
        vector<string> rst;
        int i = 0;

        while (i < str.size()) {
            int val = 0;
            while (i < str.size() && isdigit(str[i])) {
                val = val * 10 + str[i] - '0';
                ++i;
            }
            if (i < str.size() && str[i] == '#') {
                ++i;
                string s = str.substr(i, val);
                rst.push_back(s);
                i = i + val;
            }
        }

        return rst;
    }
};
