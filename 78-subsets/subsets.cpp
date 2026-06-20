class Solution {
public:
    std::vector<std::vector<int> > subsets(std::vector<int> &nums) {
		std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int> > res;
		std::vector<int> vec;
		subsets(res, nums, vec, 0);
		return res;
    }
private:
	void subsets(std::vector<std::vector<int> > &res, std::vector<int> &nums, std::vector<int> &vec, int begin) {
		res.push_back(vec);
		for (int i = begin; i != nums.size(); ++i) {
			vec.push_back(nums[i]);
			subsets(res, nums, vec, i + 1);
			vec.pop_back();
		}
	}
};