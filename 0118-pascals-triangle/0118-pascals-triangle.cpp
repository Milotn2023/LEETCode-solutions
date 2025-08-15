class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        ans[0].push_back(1);
        if(numRows==1)return ans;
        // ans[1]={1,1};
        for(int i=1;i<numRows;i++){
            vector<int>an=ans[i-1];
            vector<int>demo(an.size()+1);
            for(int j=0;j<an.size();j++){
                if(j==0){
                    demo[j]=1;
                }
                else
                demo[j]=(an[j]+an[j-1]);
            }
            demo[an.size()]=1;
            ans[i]=demo;
        }
        return ans;
    }
};