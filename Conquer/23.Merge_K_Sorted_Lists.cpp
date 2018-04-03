/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	static bool cmp(ListNode* a, ListNode* b) {
		return a->val < b->val;
	}
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		if(lists.size() == 0) 
			return NULL;
		else if(lists.size() == 1) 
			return lists[0];
		
		std::vector<ListNode*> nodeVec;
		for(int i = 0; i < lists.size(); ++i) {
			ListNode* head = lists[i];
			while(head) {
				nodeVec.push_back(head);
				head = head->next;
			}
		}
        if(nodeVec.size() == 0)
            return NULL;
		std::sort(nodeVec.begin(), nodeVec.end(), cmp);
		for(int i = 1; i < nodeVec.size(); ++i) {
			nodeVec[i-1]->next = nodeVec[i];
		}
		nodeVec[nodeVec.size()-1]->next = NULL;
		return nodeVec[0];
    }
};