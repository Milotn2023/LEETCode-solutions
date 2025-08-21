class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] && i > 0) {
                    mat[i][j] += mat[i-1][j];
                }
            }
            vector<int> count(n, 0);
            stack<int> st;
            for (int j = 0; j < n; j++) {
                while (!st.empty() && mat[i][st.top()] >= mat[i][j]) {
                    st.pop();
                }
                if (!st.empty()) {
                    int prev = st.top();
                    count[j] = count[prev] + mat[i][j] * (j - prev);
                } else {
                    count[j] = mat[i][j] * (j + 1);
                }
                res += count[j];
                st.push(j);
            }
        }
        return res;
    }
};
