class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int k = 0;

        for(int i = 0; i < nums.size(); i++){

            if(nums[i] != 0){
                nums[k] = nums[i];
                k++;
            }
        }

        for(int j = k; j < nums.size(); j++){
            nums[j] = 0;
        }
    }
};