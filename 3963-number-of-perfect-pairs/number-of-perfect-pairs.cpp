class Solution {
public:
    bool validPair(int a, int b) {
        bool minCheck = min(abs( a - b ), abs( a + b )) <= min(abs( a ), abs( b ));
        bool maxCheck = max(abs( a - b ), abs(a + b )) >= max(abs( a ), abs( b ));
        return minCheck && maxCheck;
    }

    // long long perfectPairs(vector<int>& nums) {
    //     int count = 0;
    //     for (int i = 0; i < nums.size(); i++) {
    //         for (int j = i + 1; j < nums.size(); j++) {
    //             if (validPair (nums[i], nums[j])) {
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
    // }
        long long perfectPairs(vector<int>& nums) {
        
        for (auto &x:nums){
            x=abs(x);
        }

        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            long long inequalityExpression=2*nums[i];
            auto it=upper_bound(nums.begin(),nums.end(),inequalityExpression);
            ans+=it-nums.begin()-i-1;
        }
        return ans;
    }
};