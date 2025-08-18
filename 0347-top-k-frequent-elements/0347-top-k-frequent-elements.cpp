class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>>v(20001,{0,0});
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(v[nums[i]+10000].second==0&&nums[i]!=0)v[nums[i]+10000]={1,nums[i]};
            else
            v[nums[i]+10000].first++;
        }
        sort(v.rbegin(),v.rend());
        vector<int>ans;
        int i=0;
        while(k--){
            ans.push_back(v[i].second);
            i++;
        }
        return ans;
    }
};