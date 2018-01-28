class Solution {
public:
    /*
     * @param num: a string
     * @return: true if a number is strobogrammatic or false
     */
    bool isStrobogrammatic(string &num) {
        // write your code here
        unordered_map<char, char> mp;
        mp['8'] = '8';
        mp['0'] = '0';
        mp['6'] = '9';
        mp['9'] = '6';
        mp['1'] = '1';

        int i = 0;
        int j = num.size() - 1;
        while (i <= j) {
            if (num[i] != mp[num[j]]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};
