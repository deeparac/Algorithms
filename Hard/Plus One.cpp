class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> rst(digits.begin(), digits.end());

        for (int i = rst.size() - 1; i >= 0; --i) {
            rst[i] += carry;
            carry = rst[i] / 10;
            rst[i] %= 10;
        }

        if (carry == 1) {
            rst.insert(rst.begin(), 1);
        }

        return rst;
    }
};
