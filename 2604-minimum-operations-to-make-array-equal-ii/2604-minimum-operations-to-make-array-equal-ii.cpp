class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        long long sum=0;
        long long ans=0;
        // if(k==0){
        //     if(nums1==nums2){
        //         return 0;
        //     }
        //     else 
        //     return -1;
        // }
        for(int i=0;i<n;i++){
            long long d=nums1[i]-nums2[i];
            if(k==0){
                if(d!=0)return -1;
            }
            else{
            if(d%k!=0)return -1;}
            ans+=(k==0)?0:((abs(d-0))/k);
             sum+=d;
        }
        if(sum==0)return ans/2;
        else return -1;
    }
};