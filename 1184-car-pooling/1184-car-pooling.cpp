class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int jou=0;
        for(auto &it:trips){
            jou=max(jou,it[2]);
        }
        vector<int>prefix(jou+1,0);
        for(auto &t:trips){
            prefix[t[1]]+=t[0];
            prefix[t[2]]-=t[0];
        }
        // int curr=0;  now i understand why the same things is done by curr also
        if(prefix[0]>capacity)return false;// life changing line..
        for(int i=1;i<=jou;i++){
            prefix[i]+=prefix[i-1];
            if(prefix[i]>capacity)return false;
        }
        return true;
    }
};