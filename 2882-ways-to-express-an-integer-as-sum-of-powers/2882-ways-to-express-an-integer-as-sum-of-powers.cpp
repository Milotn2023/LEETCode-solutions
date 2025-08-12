class Solution {
public:
    int numberOfWays(int k, int x) {
        vector<int>arr;
        for(int i=1;pow(i,x)<=k;i++){
            arr.push_back(pow(i,x));
        }
        int n=arr.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    // Base case: sum = 0 → 1 way (empty subsequence)
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    // Base case for the first element
    if (arr[0] <= k)
        dp[0][arr[0]] = 1;

    // Fill DP table
    for (int i = 1; i < n; i++) {
        for (int target = 0; target <= k; target++) {
            int notTake = dp[i - 1][target];
            int take = 0;
            if (arr[i] <= target)
                take = dp[i - 1][target - arr[i]];
            dp[i][target] = (take + notTake)%1000000007;
        }
    }

    return (dp[n - 1][k])%1000000007;
    }
};