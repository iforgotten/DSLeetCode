class Solution {
private:
	bool robot(int idx, std::vector<int>& nums, \
			   const int& target, int bucket[]) {
		if(idx == nums.size()) {
			return bucket[0] == target && bucket[1] == target \
				&& bucket[2] == target && bucket[3] == target;
		}
		
		for(int i = 0; i < 4; ++i) {
			if(bucket[i] + nums[idx] > target) {
				continue;
			}
			bucket[i] += nums[idx];
			if(robot(idx+1, nums, target, bucket)) {
				return true;
			}
			bucket[i] -= nums[idx];
		}
		return false;
	}
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4) {
			return false;
		}
		
		int sum = 0;
		for(int i = 0; i < nums.size(); ++i) {
			sum += nums[i];
		}
		
		if(sum % 4 != 0) {
			return false;
		}
		
		std::sort(nums.begin(), nums.end(), std::greater<int>());
		int bucket[4] = {0};
		return robot(0, nums, sum/4, bucket);
    }
};