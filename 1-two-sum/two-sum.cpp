class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
          
        
        unordered_map<int, int> map;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            if (map.find(diff) != map.end()) {
                result.push_back(i);
                result.push_back(map[diff]);
            }
            map[nums[i]] = i;
        }
        return result;
        
    }
};