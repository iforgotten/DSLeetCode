class Solution {
    void merge(std::vector<std::pair<int,int>>& set1, \
               std::vector<std::pair<int,int>>& set2,\
               std::vector<std::pair<int,int>>& vec,\
               std::vector<int>& count) {
        int i = 0;
        int j = 0;
        
        while(i < set1.size() && j < set2.size()) {
            if(set1[i].first <= set2[j].first) {
                count[set1[i].second] += j;
                vec.push_back(set1[i]);
                ++i;
            } else {
                vec.push_back(set2[j]);
                ++j;
            }
        }
        
        while(i < set1.size()) {
            count[set1[i].second] += j;
            vec.push_back(set1[i]);
            ++i;
        }
        while(j < set2.size()) {
            vec.push_back(set2[j]);
            ++j;
        }
    }
    void mergeSort(std::vector<std::pair<int,int>>& vec,\
                   std::vector<int>& count) {
        if(vec.size() < 2) 
            return;
        int mid = vec.size() >> 1;
        std::vector<std::pair<int,int>> subset1;
        std::vector<std::pair<int,int>> subset2;
        
        for(int i = 0; i < mid; ++i) {
            subset1.push_back(vec[i]);
        }
        
        for(int i = mid; i < vec.size(); ++i) {
            subset2.push_back(vec[i]);
        }
        
        mergeSort(subset1, count);
        mergeSort(subset2, count);
        vec.clear();
        merge(subset1, subset2, vec, count);
        return;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        std::vector<int> count;
        std::vector<std::pair<int,int>> vec;
        // 初始化辅助数组,绑定位置
        for(int i = 0; i < nums.size(); ++i) {
            count.push_back(0);
            vec.push_back(std::make_pair(nums[i], i));
        }
        mergeSort(vec, count);
        return count;
    }
};