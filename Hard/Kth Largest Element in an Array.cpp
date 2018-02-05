class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty()) {
            return -1;
        }

        return qSelect(nums, k, 0, nums.empty() - 1);
    }

    int qSelect(vector<int>& nums, int k, int start, int end) {
        if (start >= end) {
            return nums[start];
        }

        int mid = start + (end - start) / 2;
        int pivot = nums[mid];

        int i = start, j = end;
        while (i <= j) {
            while (i <= j && nums[i] < pivot) {
                i++;
            }

            while (i <= j && nums[j] > pivot) {
                j--;
            }

            if (i <= j) {
                swap(nums[i++], nums[j--]);
            }
        }

        if (start + k - 1 <= j) {
            return qSelect(nums, k, start, j);
        }
        if (start + k - 1 >= i) {
            return qSelect(nums, k - (i - start), i, end);
        }

        return nums[j + 1];
    }
};
