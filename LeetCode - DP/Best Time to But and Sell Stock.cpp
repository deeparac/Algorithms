class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        prices.push_back(0);
        stack<int> stk; stk.push(prices[0]);
        int rst = 0;
        int minimum = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            while (stk.empty() == false && stk.top() > prices[i]) {
                int p = stk.top(); stk.pop();
                rst = max(rst, p - minimum);
            }
            stk.push(prices[i]);
            minimum = min(minimum, prices[i]);
        }
        return rst;
    }
};
