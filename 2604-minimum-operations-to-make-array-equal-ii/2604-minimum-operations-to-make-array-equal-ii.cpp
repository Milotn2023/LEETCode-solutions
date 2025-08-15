class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<int>v(n);
        long long sum=0;
        long long ans=0;
        if(k==0){
            if(nums1==nums2){
                return 0;
            }
            else 
            return -1;
        }
        for(int i=0;i<n;i++){
            v[i]=nums1[i]-nums2[i];
            if(v[i]%k!=0)return -1;
            ans+=(abs(v[i]-0))/k;
             sum+=v[i];
        }
        if(sum==0)return ans/2;
        else return -1;
    }
};