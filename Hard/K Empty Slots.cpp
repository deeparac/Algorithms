class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int rst = -1;
        if (flowers.size() < 2) {
            return rst;
        }

        set<int> treeset;
        for (int i = 0; i < flowers.size(); ++i) {
            auto it = treeset.insert(flowers[i]).first;
            auto left = it, right = it;
            if (left != treeset.begin()) {
                left--;
            }
            if (right != treeset.end()) {
                right++;
            }

            if (*it - *left == k + 1 ||
                *right - *it == k + 1) {
                rst = i + 1;
                break;
            }
        }

        return rst;
    }
};
