class Solution {
public:
    long long flowerGame(int n, int m) {
        int odd1=ceil(n/2.0),even1=n/2;
        int odd2=ceil(m/2.0),even2=m/2;
        long long ans=(1ll*odd1*even2)+(1ll*odd2*even1);
        return ans;
    }
};