class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // vector<vector<int>>ans(numRows);
        // ans[0].push_back(1);
        // if(numRows==1)return ans;
        // // ans[1]={1,1};
        // for(int i=1;i<numRows;i++){
        //     vector<int>an=ans[i-1];
        //     vector<int>demo(an.size()+1);
        //     for(int j=0;j<an.size();j++){
        //         if(j==0){
        //             demo[j]=1;
        //         }
        //         else
        //         demo[j]=(an[j]+an[j-1]);
        //     }
        //     demo[an.size()]=1;
        //     ans[i]=demo;
        // }
        // return ans;
        vector<vector<int>> ans;
    ans.reserve(numRows); // avoid reallocations

    for (int i = 0; i < numRows; i++) {
        ans.push_back(vector<int>(i + 1, 1)); // first and last = 1
        for (int j = 1; j < i; j++) {
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }
    return ans;
    }
};