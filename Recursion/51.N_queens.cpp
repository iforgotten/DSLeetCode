class Solution {
private:
	void put(int x, int y, std::vector<std::vector<int>>& mark) {
		static const int dx[] = {0,1,1,1,0,-1,-1,-1};
		static const int dy[] = {-1,-1,0,1,1,1,0,-1};
		mark[x][y] = 1;
		
		int newx = -1;
		int newy = -1;
		int n = mark.size();
		for(int i = 1; i < n; ++i) {
			for(int j = 0; j < 8; ++j) {
				newx = x + i * dx[j];
				newy = y + i * dy[j];
				
				if(newx >= 0 && newx < n && \
				   newy >= 0 && newy < n) {
						mark[newx][newy] = 1;
				}
			}
		}
	}
	
	void robot(int idx, const int& n, \
				std::vector<std::vector<int>>& mark,\
				std::vector<std::string>& item, \
				std::vector<std::vector<std::string>>& result) {
		if(idx == n) {
			result.push_back(item);
			return;
		}
		
		for(int i = 0; i < n; ++i) {
			if(mark[idx][i] == 0) {
				std::vector<std::vector<int>> tmp = mark;
				item[idx][i] = 'Q';
				put(idx, i, mark);
				robot(idx+1, n, mark, item, result);
				mark = tmp;
				item[idx][i] = '.';
			}
		}
	}
	
public:
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> result;
		std::vector<std::string> item;
		std::vector<std::vector<int>> mark;
		
		for(int i = 0; i < n; ++i) {
			mark.push_back(std::vector<int>());
			for(int j = 0; j < n; ++j) {
				mark[i].push_back(0);
			}
			item.push_back("");
			item[i].append(n, '.');
		}
		
		robot(0, n, mark, item, result);
		return result;
    }
};


