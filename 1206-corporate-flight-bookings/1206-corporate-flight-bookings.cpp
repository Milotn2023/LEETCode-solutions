class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>prefix(n+2,0);
        for(auto &i:bookings){
            prefix[i[0]]+=i[2];
            prefix[i[1]+1]-=i[2];
        }
        for(int i=1;i<=n;i++){
            prefix[i]+=prefix[i-1];
        }
        return vector<int>(prefix.begin()+1,prefix.begin()+n+1);
    }
};