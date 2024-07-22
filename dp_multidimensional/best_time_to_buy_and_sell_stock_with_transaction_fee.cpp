// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/?envType=study-plan-v2&envId=leetcode-75

#include <algorithm>
#include <vector>

class Solution {
public:
    vector<vector<int>> dp;
    int _maxProfit(std::vector<int>::size_type pos, bool hold, std::vector<int>& prices, int& fee) {
        if (pos >= prices.size()) {
            return 0;
        }

        if (dp[pos][hold] != -1) {
            return dp[pos][hold];
        }

        int currPrice = prices[pos];
        int buyOrSell;
        int wait;
        if (hold) {
            buyOrSell = currPrice - fee + _maxProfit(pos + 1, false, prices, fee);
            wait = _maxProfit(pos + 1, hold, prices, fee);
        } else {
            buyOrSell = -currPrice + _maxProfit(pos + 1, true, prices, fee);
            wait = _maxProfit(pos + 1, hold, prices, fee);
        }

        return dp[pos][hold] = std::max(buyOrSell, wait);
    }

    int maxProfit(std::vector<int>& prices, int fee) {
        dp = vector<vector<int>>(prices.size(), vector<int>(2, -1));
        return _maxProfit(0, false, prices, fee);
    }
};
