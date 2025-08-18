class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n+1,1);
        vector<int>right(n+1,1);
        for(int i=0;i<n;i++){
            left[i+1]=left[i]*nums[i];
        }
        for(int i=n-1;i>=0;i--){
            right[i]=right[i+1]*nums[i];
        }
        vector<int>ans(n,1);
        for(int i=0;i<n;i++)
        ans[i]=right[i+1]*left[i];
        return ans;
    }
};