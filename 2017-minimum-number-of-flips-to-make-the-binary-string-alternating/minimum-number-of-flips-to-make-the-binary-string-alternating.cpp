class Solution {
public:
    int minFlips(string s) {

        int n = s.size();
        string s2 = s + s;

        int diff1 = 0, diff2 = 0;
        int ans = INT_MAX;

        for (int i = 0; i < s2.size(); i++) {

            int bit = s2[i] - '0';

            // pattern 010101...
            diff1 += bit ^ (i % 2);

            // pattern 101010...
            diff2 += bit ^ (1 - (i % 2));

            // remove element leaving window
            if (i >= n) {
                int old = s2[i - n] - '0';
                diff1 -= old ^ ((i - n) % 2);
                diff2 -= old ^ (1 - ((i - n) % 2));
            }

            // window size reached
            if (i >= n - 1) {
                ans = min(ans, min(diff1, diff2));
            }
        }

        return ans;
    }
};