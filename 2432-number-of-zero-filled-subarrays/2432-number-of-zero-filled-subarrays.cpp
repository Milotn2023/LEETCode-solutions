class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
    int n=nums.size();
    vector<int>v;
    int count=0;
    long long ans=0;
    for(int i=0;i<n;i++){
        if(nums[i]==0){count++;ans+=count;}
        else{
            if(count!=0){
                v.push_back(count);
                count=0;
            }
        }
    }
    return ans;
    }
};