#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Find bounding box of all 1's
    tuple<int,int,int,int> findBounding(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int low_x = INT_MAX, high_x = -1, low_y = INT_MAX, high_y = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    low_x = min(low_x, i);
                    high_x = max(high_x, i);
                    low_y = min(low_y, j);
                    high_y = max(high_y, j);
                }
            }
        }
        return {low_x, high_x, low_y, high_y};
    }

    // Minimum area covering all 1's in subgrid
    int minArea(int x1, int x2, int y1, int y2, vector<vector<int>>& grid) {
        int min_x = INT_MAX, max_x = -1, min_y = INT_MAX, max_y = -1;
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                if (grid[i][j] == 1) {
                    min_x = min(min_x, i);
                    max_x = max(max_x, i);
                    min_y = min(min_y, j);
                    max_y = max(max_y, j);
                }
            }
        }
        if (min_x == INT_MAX) return 0; // no 1's in this subgrid
        return (max_x - min_x + 1) * (max_y - min_y + 1);
    }

    int minimumSum(vector<vector<int>>& grid) {
        auto [low_x, high_x, low_y, high_y] = findBounding(grid);
        if (low_x == INT_MAX) return 0; // no 1's at all

        int ans = INT_MAX;

        // Try 4 "L" splits
        for (int i = low_x; i < high_x; i++) {
            for (int j = low_y; j < high_y; j++) {
                // Up
                ans = min(ans,
                    minArea(low_x, i, low_y, j, grid) +
                    minArea(low_x, i, j+1, high_y, grid) +
                    minArea(i+1, high_x, low_y, high_y, grid));

                // Right
                ans = min(ans,
                    minArea(low_x, high_x, low_y, j, grid) +
                    minArea(low_x, i, j+1, high_y, grid) +
                    minArea(i+1, high_x, j+1, high_y, grid));

                // Down
                ans = min(ans,
                    minArea(low_x, i, low_y, high_y, grid) +
                    minArea(i+1, high_x, low_y, j, grid) +
                    minArea(i+1, high_x, j+1, high_y, grid));

                // Left
                ans = min(ans,
                    minArea(low_x, i, low_y, j, grid) +
                    minArea(i+1, high_x, low_y, j, grid) +
                    minArea(low_x, high_x, j+1, high_y, grid));
            }
        }

        // Horizontal 3-strips
        for (int i = low_x; i < high_x - 1; i++) {
            for (int j = i+1; j < high_x; j++) {
                ans = min(ans,
                    minArea(low_x, i, low_y, high_y, grid) +
                    minArea(i+1, j, low_y, high_y, grid) +
                    minArea(j+1, high_x, low_y, high_y, grid));
            }
        }

        // Vertical 3-strips
        for (int i = low_y; i < high_y - 1; i++) {
            for (int j = i+1; j < high_y; j++) {
                ans = min(ans,
                    minArea(low_x, high_x, low_y, i, grid) +
                    minArea(low_x, high_x, i+1, j, grid) +
                    minArea(low_x, high_x, j+1, high_y, grid));
            }
        }

        return ans;
    }
};
