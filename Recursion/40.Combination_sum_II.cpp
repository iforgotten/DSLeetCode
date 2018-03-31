class Solution {
private:
	void robot(int idx, std::vector<int>& nums,\
			   std::set<std::vector<int>>& de, int& sum, const int& target,\
			   std::vector<int>& item, std::vector<std::vector<int>>& result) {
		if(sum > target) {
			return;
		} else if(idx == nums.size() || sum == target) {
			if((sum == target) && (de.find(item) == de.end())) {
				de.insert(item);
				result.push_back(item);
				return;
			}
			return;
		}
		
		item.push_back(nums[idx]);
        sum += nums[idx];
		robot(idx+1, nums, de, sum, target, item, result);
        sum -= item.back();
		item.pop_back();
		robot(idx+1, nums, de, sum, target, item, result);
	}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
		int sum = 0;
		std::vector<int> item;
		std::vector<std::vector<int>> result;
		std:set<std::vector<int>> de;
		
		robot(0, candidates, de, sum, target, item, result);
		return result;
    }
};