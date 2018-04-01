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

class Solution {
public:
    bool makesquare(vector<int>& nums) {
		if(nums.size() < 4)
			return false;
		
		int sum = 0;
		for(int i = 0; i < nums.size(); ++i) {
			sum += nums[i];
		}
        
		if(sum % 4 != 0) {
			return false;
		}
		
		int target = sum / 4;
		std::vector<int> subset;
		std::vector<int> halfset;
		int all = 1 << nums.size();
				
		for(int i = 0; i < all; ++i) {
			int sum = 0;
			for(int j = 0; j < nums.size(); ++j) {
				if(i & (1 << j)) {
					sum += nums[j];
				}
			}
			if(sum == target) {
				subset.push_back(i);
			}
		}
		
		for(int i = 0; i < subset.size(); ++i) {
			for(int j = i + 1 ; j < subset.size(); ++j) {
				if((subset[i] & subset[j]) == 0) {
					halfset.push_back(subset[i] | subset[j]);
				}
			}
		}
		
		for(int i = 0; i < halfset.size(); ++i) {
			for(int j = i + 1; j < halfset.size(); j++) {
				if((halfset[i] & halfset[j]) == 0) {
					return true;
				}
			}
		}
		return false;
	}
};