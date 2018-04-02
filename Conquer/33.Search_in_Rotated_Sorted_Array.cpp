class Solution {
	int binarySearch(const std::vector<int>& nums, const int& target,\
					 int lo, int hi) { 
		if(lo >= hi || lo >= nums.size() || hi > nums.size()) 
			return -1;
		// [lo, hi)
		int mid = -1;
		while(lo < hi) {
			mid = (lo + hi) >> 1;
			if(nums[mid] == target) 
				return mid;
			else if(nums[mid] < target) 
				lo = mid + 1;
			else
				hi = mid;
		}
		
		return -1;
	}
	
	int binSearch(const std::vector<int>& nums, const int& target) {
		int size = nums.size();
		if(size == 1) {
			return (target == nums[0]) ? 0 : -1;
		} 
		
		int split = size;
		for(int i = 1; i < size; ++i) {
			if(nums[i-1] < nums[i])
				continue;
			split = i;
			break;
		}
		
		// [0, split)
		int ret = binarySearch(nums, target, 0, split);
		if(ret == -1) 
			return binarySearch(nums, target, split, size);
		else 
			return ret;
	}
public:
    int search(vector<int>& nums, int target) {
       return binSearch(nums, target);
    }
};