class Solution {
public:
    /**
     * @param strs: the given array of strings
     * @return: The anagrams which have been divided into groups
     */
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        // write your code here
        vector<vector<string>> rst;
        unordered_map<string, vector<string>> map;
        for (auto& str : strs) {
            string cpy = str;
            sort(cpy.begin(), cpy.end());
            map[cpy].push_back(str);
        }

        for (auto& p : map) {
            vector<string> vec = p.second;
            sort(vec.begin(), vec.end());
            rst.push_back(vec);
        }
        sort(rst.begin(), rst.end());
        return rst;
    }
};
