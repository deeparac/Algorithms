class Solution {
public:
    /*
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string s) {
        // write your code here
        vector<int> map(256, 0);
        for (int i = 0; i < s.size(); ++i) {
            map[s[i]]++;
        }

        bool flag = false;
        int sum_even = 0;
        for (int i = 0; i < map.size(); ++i) {
            if (map[i] == 0) {
                continue;
            }

            if (map[i] % 2 == 0) {
                sum_even += map[i];
            } else {
                flag = true;
                if (map[i] > 2) {
                    sum_even += map[i] - 1;
                }
            }
        }

        return flag ? sum_even + 1 : sum_even;
    }
};
