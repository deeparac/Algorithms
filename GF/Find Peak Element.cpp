class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        } else if (nums.size() == 2) {
            if (nums[0] > nums[1]) {
                return 0;
            } else {
                return 1;
            }
        }

        int start = 0;
        int end = nums.size() - 1;

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }

            if (nums[mid] > nums[mid - 1]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        if (nums[start] > nums[start - 1] && nums[start] > nums[start + 1]) {
            return start;
        } else {
            return end;
        }
    }
};
