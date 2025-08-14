class Solution {
public:
    string largestGoodInteger(string num) {
        char maxi = 0; // 0 means no triple found yet
    for (int i = 0; i + 2 < num.size(); ++i) {
        if (num[i] == num[i+1] && num[i] == num[i+2]) {
            maxi = max(maxi, num[i]);
        }
    }
    return maxi ? string(3, maxi) : "";
    }
};