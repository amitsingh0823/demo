class Solution {
public:
    bool areSimilar(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        k = k % n;

        for (int i = 0; i < m; i++) {
            vector<int> temp = grid[i];  // copy row

            if (i % 2 == 0) {
                // even row → left shift
                rotate(temp.begin(), temp.begin() + k, temp.end());
            } else {
                // odd row → right shift
                rotate(temp.begin(), temp.end() - k, temp.end());
            }

            // compare with original row
            if (temp != grid[i]) {
                return false;
            }
        }

        return true;
    }
};