class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int t = 1; t <= n; ++t) {
                dp[i][t] = max(
                    dp[i + 1][t],                                 
                    satisfaction[i] * t + dp[i + 1][t + 1]        
                );
            }
        }

        return dp[0][1];
    }
};
