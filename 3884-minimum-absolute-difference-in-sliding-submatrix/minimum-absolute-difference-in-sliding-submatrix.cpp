class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
           int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1, 0));

    // Iterate over all k x k submatrices
    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= m - k; j++) {

            set<int> st;

            // Traverse k x k submatrix
            for (int x = i; x < i + k; x++) {
                for (int y = j; y < j + k; y++) {
                    st.insert(grid[x][y]);
                }
            }

            // Find minimum absolute difference
            int minDiff = INT_MAX;

            if (st.size() < 2) {
                ans[i][j] = 0; // only one unique element
                continue;
            }

            auto it = st.begin();
            auto prev = it;
            it++;

            while (it != st.end()) {
                minDiff = min(minDiff, abs(*it - *prev));
                prev = it;
                it++;
            }

            ans[i][j] = minDiff;
        }
    }

    return ans;
    }
};