class Solution {
	void robot(std::string item, int left, int right, std::vector<string>& result) {
		if(left == 0 && right == 0) {
			result.push_back(item);
			return;
		}
		
		if(0 < left) {
			robot(item + '(',left-1, right, result);
		}
		
		if(left < right) {
			robot(item + ')',left, right-1, result);
		}
	}
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> result;
		robot("", n, n, result);
		return result;
    }
};