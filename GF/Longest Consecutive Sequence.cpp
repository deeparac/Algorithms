class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        unordered_set<int> s;
        int rst = 0;

        for (const auto i : nums) {
            s.insert(i);
        }

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int tmp = 1;
            if (s.find(num) != s.end()) {
                int small = num - 1;
                int large = num + 1;
                while (s.find(small) != s.end()) {
                    cout << small << endl;
                    tmp += 1;
                    s.erase(small);
                    small -= 1;
                }
                while (s.find(large) != s.end()) {
                    cout << large << endl;
                    tmp += 1;
                    s.erase(large);
                    large += 1;
                }
            }
            rst = max(rst, tmp);
            s.erase(num);
        }

        return rst;
    }
};
