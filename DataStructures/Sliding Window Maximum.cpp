class Solution {
public:
    /*
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The maximum number inside the window at each moving
     */
    vector<int> maxSlidingWindow(vector<int> nums, int k) {
        // write your code here
        if (nums.empty() || nums.size() < k) {
            return vector<int>();
        }

        vector<int> rst;
        deque<int>  dq;

        for (int i = 0; i < k - 1; ++i) {
            enQueue(dq, nums[i]);
        }

        for (int i = k - 1; i < nums.size(); ++i) {
            enQueue(dq, nums[i]);
            rst.push_back(dq.front());
            popQueue(dq, nums[i - k + 1]);
        }

        return rst;
    }

    void enQueue(deque<int>& dq, int num) {
        while (!dq.empty() && dq.back() < num) {
            dq.pop_back();
        }
        dq.push_back(num);
    }

    void popQueue(deque<int>& dq, int num) {
        if (dq.front() == num) {
            dq.pop_front();
        }
    }
};
