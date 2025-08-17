class Solution {
public:
    long long calculateProfit(vector<int>& prices, vector<int> strategy) {
        long long profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            profit += prices[i] * strategy[i];
        }
        return profit;
    }

    vector<int> changeStrategy(int left, int k, vector<int> strategy) {
        int hold = k / 2, sell = k / 2;
        for (int i = left; i < strategy.size(); i++) {
            if (hold > 0) {
                strategy[i] = 0;
                --hold;

            } else if (sell > 0) {
                strategy[i] = 1;
                --sell;
            }
        }
        return strategy;
    }

    // long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {

    //     int n = prices.size();
    //     long long profit = 0;
    //     int i = 0;

    //     profit = calculateProfit(prices, strategy);

    //     while (i < n - k +1) {

    //         vector<int> modifyStrategy = changeStrategy(i, k, strategy);

    //         long long sub_profit = calculateProfit(prices, modifyStrategy);
    //         profit = max(profit, sub_profit);
    //         i++;
    //     }

    //     return profit;
    // }
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {

        int n = prices.size();

        // prefix sum of prices
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + prices[i];
        }

        // prefix sum of (strategy[i] * prices[i])
        vector<long long> origPrefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            origPrefix[i + 1] = origPrefix[i] + 1LL * strategy[i] * prices[i];
        }

        // base profit (original strategy)
        long long base = origPrefix[n];

        long long bestGain = 0; // modification is optional
        for (int L = 0; L + k <= n; L++) {
            long long orig = origPrefix[L + k] - origPrefix[L];
            long long mod = prefix[L + k] - prefix[L + k / 2];
            long long gain = mod - orig;
            bestGain = max(bestGain, gain);
        }

        return base + bestGain;
    }
};