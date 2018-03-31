bool canJump(vector<int>& nums) {
	std::vector<int> index;
	for(int i = 0; i < nums.size(); ++i) {
		index.push_back(nums[i] + i);
	}

	int jump = 0;
	int maxIdx = index[0];
	for(; jump < index.size(); ++i) {
		if(jump > maxIdx) {
			break;
		}
		if(index[i] > maxIdx) {
			maxIdx = index[i];
		}
	}

	if(jump >= nums.size()) 
		return true;
	return false;
}
