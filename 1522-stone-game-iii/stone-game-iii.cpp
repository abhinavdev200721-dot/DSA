class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(4, 0);
        for (int i = n - 1; i >= 0; --i) {
            int take = 0;
            int max_diff = INT_MIN;
            for (int k = 0; k < 3 && i + k < n; ++k) {
                take += stoneValue[i + k];
                max_diff = max(max_diff, take - dp[(i + k + 1) % 4]);
            }
            dp[i % 4] = max_diff;
        }
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};
