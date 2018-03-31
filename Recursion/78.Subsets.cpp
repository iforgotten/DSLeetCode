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

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		std::vector<std::vector<int>> result;
		// 计算所有可能的取值范围
		int all_set = 1 << nums.size();
		
		for(int i = 0; i < all_set; ++i) {
			std::vector<int> item;
			for(int j = 0; j < nums.size(); ++j) {
				if(i & (1 << j)) {
					item.push_back(nums[j]);
				}
			}
			result.push_back(item);
		}
		return result;
    }
};
