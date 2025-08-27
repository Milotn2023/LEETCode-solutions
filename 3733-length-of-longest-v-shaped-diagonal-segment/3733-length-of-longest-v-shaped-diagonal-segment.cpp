class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // diagonal directions in clockwise order: ↗, ↘, ↙, ↖
        vector<pair<int,int>> dirs = {{-1,1}, {1,1}, {1,-1}, {-1,-1}};
        auto in = [&](int x, int y){ return x >= 0 && x < m && y >= 0 && y < n; };

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) continue;       // must start from 1

                for (int d = 0; d < 4; ++d) {
                    // build the straight path along direction d (values alternate 2,0,2,...)
                    vector<pair<int,int>> path;
                    int x = i + dirs[d].first;
                    int y = j + dirs[d].second;
                    int expected = 2;
                    while (in(x,y) && grid[x][y] == expected) {
                        path.emplace_back(x,y);
                        expected = (expected == 2 ? 0 : 2);
                        x += dirs[d].first;
                        y += dirs[d].second;
                    }

                    // no-turn length (just straight)
                    ans = max(ans, (int)path.size() + 1); // +1 for starting '1'

                    // try turning once (90° clockwise) at each prefix position of the path
                    int nd = (d + 1) % 4; // clockwise turn
                    for (int p = 0; p < (int)path.size(); ++p) {
                        // position after consuming prefix up to path[p]
                        int tx = path[p].first + dirs[nd].first;
                        int ty = path[p].second + dirs[nd].second;
                        // if p is even -> path[p] is 2, next expected is 0; if p odd -> next expected is 2
                        int nextExpected = (p % 2 == 0) ? 0 : 2;
                        int extra = 0;
                        while (in(tx, ty) && grid[tx][ty] == nextExpected) {
                            ++extra;
                            nextExpected = (nextExpected == 2 ? 0 : 2);
                            tx += dirs[nd].first;
                            ty += dirs[nd].second;
                        }
                        int total = 1 + (p + 1) + extra; // 1 (start '1') + prefix length + extra after turn
                        ans = max(ans, total);
                    }
                }
            }
        }
        return ans;
    }
};