class Solution {
public:
    /*
     * @param k: An integer
     * @param nums: An integer array
     * @return: kth smallest element
     */
    int kthSmallest(int k, vector<int> nums) {
        // write your code here
        return quickSelect(nums, 0, nums.size() - 1, k - 1);
    }

private:
    int quickSelect(vector<int>& nums, int start, int end, int k) {
        if (start == end) {
            return nums[start];
        }

        int mid = start + (end - start) / 2;
        int left = start;
        int right = end;
        int pivot = nums[mid];

        while (left <= right) {
            while (left <= right && nums[left] < pivot) {
                left++;
            }
            while (left <= right && nums[right] > pivot) {
                right--;
            }

            if (left <= right) {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }

        if (right >= k && start <= right) {
            return quickSelect(nums, start, right, k);
        } else if (left <= k && left <= end) {
            return quickSelect(nums, left, end, k);
        } else {
            return nums[k];
        }
    }
};
