class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wlist(wordList.begin(), wordList.end());
        int rst = INT_MAX;

        unordered_map<string, int> map;
        queue<string> q;
        map[beginWord] = 1;
        q.push(beginWord);

        while (!q.empty()) {
            string word = q.front(); q.pop();
            for (int i = 0; i < word.size(); ++i) {
                string newWord = word;
                for (char c = 'a'; c <= 'z'; ++c) {
                    newWord[i] = c;
                    if (wlist.find(newWord) != wlist.end() && newWord == endWord) {
                        rst = min(rst, map[word] + 1);
                    }
                    if (wlist.find(newWord) != wlist.end() && map.find(newWord) == map.end()) {
                        q.push(newWord);
                        map[newWord] = map[word] + 1;
                    }
                }
            }
        }

        return rst == INT_MAX ? 0 : rst;
    }
};
