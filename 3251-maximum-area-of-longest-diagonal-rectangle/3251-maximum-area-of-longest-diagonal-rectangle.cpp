class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
         int diagonal=0,ans=0;
        for(int i=0;i<d.size();i++){
            int temp=pow(d[i][0],2)+pow(d[i][1],2);
            if(temp>=diagonal){
                if(temp==diagonal)
                ans=max(ans,d[i][0]*d[i][1]);
                else ans=d[i][0]*d[i][1];
                diagonal =temp;
            }
        }
        return ans;
    }
};