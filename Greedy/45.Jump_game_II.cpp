class Solution {
public:
    int jump(vector<int>& nums) {
		if(nums.size() < 2) {
			return 0;
		}
		
		int minJump = 1;
		int curMaxIdx = nums[0];
		int preMaxIdx = nums[0];
		
		for(int i = 1; i < nums.size(); ++i) {
			if(curMaxIdx < i) {
				++minJump;
				curMaxIdx = preMaxIdx;
			}
			
			if(preMaxIdx < (nums[i] + i)) {
				preMaxIdx = nums[i] + i;
			}
		}
		
		return minJump;
    }
};