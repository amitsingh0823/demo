class Solution {
public:
    bool areSimilar(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        k = k % n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int newCol;

                if (i % 2 == 0) {
                    // even row → left shift
                    newCol = (j + k) % n;
                } else {
                    // odd row → right shift
                    newCol = (j - k + n) % n;
                }

                if (grid[i][j] != grid[i][newCol]) {
                    return false;
                }
            }
        }

        return true;
    }
};