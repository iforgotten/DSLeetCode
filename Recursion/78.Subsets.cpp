class Solution {
private:
	void generate(int idx, \
				std::vector<int>& nums, \
				std::vector<int>& item, \
				std::vector<std::vector<int>>& result) {
		if(idx == nums.size()) {
			result.push_back(item);
			return;
		}
		
		item.push_back(nums[idx]);
		generate(idx+1, nums, item, result);
		item.pop_back();
		generate(idx+1, nums, item, result);
	}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<int> item;
		std::vector<std::vector<int>> result;
		generate(0, nums, item, result);
		return result;
    }
};