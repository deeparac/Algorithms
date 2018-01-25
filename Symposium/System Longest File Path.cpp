class Solution {
public:
    /*
     * @param input: an abstract file system
     * @return: return the length of the longest absolute path to file
     */
    int lengthLongestPath(string &input) {
        // write your code here
        unordered_map<int, int> map{{0, 0}};
        int rst = 0;
        int level = 0;

        for (int i = 0; i < input.size(); ++i) {
            int start = i;
            while (i < input.size() && input[i] != '\n' && input[i] != '\t') {
                ++i;
            }

            if (i >= input.size() || input[i] == '\n') {
                string t = input.substr(start, i - start);
                if (t.find('.') != string::npos) {
                    rst = max(rst, map[level] + (int)t.size());
                } else {
                    map[++level] = map[level - 1] + (int)t.size() + 1;
                }

                level = 0;
            } else {
                level += 1;
            }
        }

        return rst;
    }
};
