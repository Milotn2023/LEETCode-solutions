class Solution {
public:
    int fun(vector<int>&v,int ind,vector<int>&dp){
        if(ind+1>v.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        // return max(v[ind]*ind+fun(v,ind+2),v[ind+1]*(ind+1)+fun(v,ind+1));
        // The corrected recursive call
return dp[ind]=max( v[ind]*ind + fun(v, ind+2,dp), 0 + fun(v, ind+1,dp) );
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int>v(maxi+1,0);
        vector<int>dp(maxi+1,-1);
        for(int i=0;i<nums.size();i++){
            v[nums[i]]++;
        }
        return fun(v,0,dp);
        
    }
};