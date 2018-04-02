class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        std::vector<int> result;
		
		bool isOK = false;
		int lo = 0;
		int hi = nums.size();
		int mid = -1;
		
		while(lo < hi) {
			mid = (lo + hi) >> 1;
			if(nums[mid] == target) {
				isOK = true;
				break;
			} else if(target < nums[mid]) {
				hi = mid;
			} else if(nums[mid] < target){
				lo = mid + 1;
			}
		}
		
		if(isOK) {
            int idx = mid;
            while(target == nums[mid] && 0 <= mid) {
                --mid;
            }
            result.push_back(mid+1);
			int size = nums.size();
            mid = idx;
			while(target == nums[mid] && mid < size) {
				++mid;
			}

			result.push_back(mid-1);
			return result;
		} else {
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}
    }
};
