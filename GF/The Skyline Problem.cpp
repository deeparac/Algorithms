class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector< pair<int, int> > rst;
        if (buildings.empty()) {
            return rst;
        }

        vector< pair<int, int> > heights;
        for (const auto& building : buildings) {
            heights.push_back(make_pair(building[0], -building[2]));
            heights.push_back(make_pair(building[1], building[2]));
        }
        sort(heights.begin(), heights.end());
        multiset<int> heap;
        heap.insert(0);
        int pre = 0;
        int cur = 0;

        for (const auto& height : heights) {
            if (height.second < 0) {
                heap.insert(-height.second);
            } else {
                heap.erase(heap.find(height.second));
            }

            cur = *heap.rbegin();
            if (cur != pre) {
                rst.push_back(make_pair(height.first, cur));
                pre = cur;
            }
        }

        return rst;
    }
};
