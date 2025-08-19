class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>>v1(m,vector<int>(n,0));
        vector<int>v;
        int i=0,j=0;
        v.push_back(matrix[0][0]);
        v1[0][0]=1;
        int t=m*n;
        while(t>1){
            while(j+1<n&&!v1[i][j+1]){
                j=j+1;
                v1[i][j]=1;
                v.push_back(matrix[i][j]);
                t--;
            }
            while(i+1<m&&!v1[i+1][j]){
                i=i+1;
                v1[i][j]=1;
                v.push_back(matrix[i][j]);
                t--;
            }
            while(j-1>=0&&!v1[i][j-1]){
                j=j-1;
                v1[i][j]=1;
                v.push_back(matrix[i][j]);
                t--;
            }
            while(i-1>0&&!v1[i-1][j]){
                i=i-1;
                v1[i][j]=1;
                v.push_back(matrix[i][j]);
                t--;
            }
        }
        return v;
    }
};