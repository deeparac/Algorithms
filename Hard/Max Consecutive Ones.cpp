class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int rst = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 1) {
                rst = max(rst, cnt);
                cnt = 0;
            } else {
                cnt++;
            }
        }

        return max(rst, cnt);
    }
};
