class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index=0;
        for(int i=0;i<nums.size();i++){
            index=max(index,i+nums[i]);
            if(nums[i]==0){
                if(index<=i&&i!=nums.size()-1)return false;
            }
        }
        return true;
    }
};