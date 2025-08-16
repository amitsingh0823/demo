class Solution {
public:
    int minSensors(int n, int m, int k) {
        int block = 2*k +1;
        int row_needed=(n + block-1) / block;
        int column_needed=(m + block -1) /block;
      
        return row_needed*column_needed;
    }
};