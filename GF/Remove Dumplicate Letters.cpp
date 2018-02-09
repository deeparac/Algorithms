class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> map(256, 0);
        vector<bool> visited(256, false);
        string rst = "0";

        for (int i = 0; i < s.length(); ++i) {
            map[s[i]] += 1;
        }

        for (int i = 0; i < s.length(); ++i) {
            map[s[i]] -= 1;
            if (visited[s[i]]) {
                continue;
            }

            while (s[i] < rst.back() && map[rst.back()]) {
                visited[rst.back()] = false;
                rst.pop_back();
            }

            rst += s[i];
            visited[s[i]] = true;
        }

        return rst.substr(1);
    }
};
