class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums[0] == target) 
			return 0;
		else if (nums[nums.size()-1] == target) {
			return nums.size()-1;
		}
		
		// [0, hi)
		int lo = 0;
		int hi = nums.size();
		int mid = 0;
		int preIdx = -1;
		while(lo < hi) {
			mid = (lo + hi) >> 1;
			if(nums[mid] == target) {
				return mid;
			}
            
			preIdx = mid;
			if(target < nums[mid]) {
				hi = mid;
			} else if(nums[mid] < target) {
				lo = mid+1;
			}
		}
		
		if(target < nums[preIdx]) {
			return preIdx;
		} else if(nums[preIdx] < target) {
			return preIdx+1;
		}
	}
};