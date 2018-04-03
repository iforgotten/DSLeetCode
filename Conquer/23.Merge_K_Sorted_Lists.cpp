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

class Solution {
	ListNode* merge(ListNode* l1, ListNode* l2) {
    	ListNode temp_head(0);
    	ListNode *pre = &temp_head;
    	while (l1 && l2){
	    	if (l1->val < l2->val){
	    		pre->next = l1;
	    		l1 = l1->next;
	    	}
	    	else{
	    		pre->next = l2;
	    		l2 = l2->next;
	    	}
	    	pre = pre->next;
	    }
	    if (l1){
    		pre->next = l1;
    	}
    	if (l2){
	    	pre->next = l2;
	    }
        return temp_head.next;
	}
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if(lists.size() == 0) 
			return NULL;
		else if(lists.size() == 1) 
			return lists[0];
		
		std::vector<ListNode*> subset1;
		std::vector<ListNode*> subset2;
		
		int mid = lists.size() >> 1;
		for(int i = 0; i < mid; ++i) {
			subset1.push_back(lists[i]);
		}
		for(int i = mid; i < lists.size(); ++i) {
			subset2.push_back(lists[i]);
		}
		ListNode* l1 = mergeKLists(subset1);
		ListNode* l2 = mergeKLists(subset2);
		return merge(l1, l2);
	}
};
