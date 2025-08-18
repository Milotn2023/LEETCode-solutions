#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return dfs(nums);
    }
private:
    bool dfs(vector<double>& nums) {
        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < 1e-6;
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                vector<double> next;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }
                double x = nums[i], y = nums[j];
                vector<double> results = {
                    x + y,x - y,y - x,x * y
                };
                if (fabs(y) > 1e-6) results.push_back(x / y);
                if (fabs(x) > 1e-6) results.push_back(y / x);
                for (double r : results) {
                    next.push_back(r);
                    if (dfs(next)) return true;
                    next.pop_back();  // backtrack
                }
            }
        }
        return false;
    }
};
