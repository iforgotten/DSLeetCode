class Solution {
private:
	void robot(int idx, \
			   const std::vector<int>& nums,\
			   std::vector<int>& item, \
			   std::vector<std::vector<int>>& result,\
			   std::set<std::vector<int>>& de) {
		if(idx == nums.size()) {
			if(de.find(result[i]) == de.end()) {
				de.insert(item);
				result.push_back(item);
			}
			return;
		}
		
		item.push_back(nums[idx]);
		robot(idx+1, nums, item, result);
		item.pop_back();
		robot(idx+1, nums, item, result);
	}
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::vector<std::vector<int>> result;
		std::vector<int> item;
		// 并不优雅，利用的set集合的特性进行去重的。
		// 想要优雅，再选择元素的时候，直接就过滤了的话，可以提高不少效率
		std::set<std::vector<int>> de;
		robot(0, nums, item, result, de);
		return result;
    }
};

