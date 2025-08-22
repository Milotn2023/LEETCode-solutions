class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int left=n,right=-1,top=m,bottom=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    left=min(left,j);
                    right=max(right,j);
                    top=min(top,i);
                    bottom=max(bottom,i);
                }
            }
        }
        if(left>right)return 0;
        return (right-left+1)*(bottom-top+1);
    }
};