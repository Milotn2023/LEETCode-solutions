class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
    int n=nums.size();
    vector<int>v;
    int count=0;
    for(int i=0;i<n;i++){
        if(nums[i]==0)count++;
        else{
            if(count!=0){
                v.push_back(count);
                count=0;
            }
        }
    }
    if(count!=0)v.push_back(count);
    long long ans=0;
    for(int i=0;i<v.size();i++){
        int t=v[i];
        ans+=(1ll*t*(t+1))/2;
    }
    return ans;
    }
};