class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur = 0;
        int rst = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cnt++;
            if (nums[i] == 0) {
                cur = cnt;
                cnt = 0;
            }
            rst = max(rst, cnt + cur);
        }
        return rst;
    }
};
