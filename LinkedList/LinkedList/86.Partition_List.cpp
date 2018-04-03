/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode headNode(0);
        headNode.next = head;
        ListNode newList(0);

        ListNode* pNew = &newList;
        ListNode* preNode = &headNode;
        ListNode* pNode = head;
        
        while(pNode) {
            if(pNode->val < x) {
                preNode->next = pNode->next;
                pNode->next = NULL;
                pNew->next = pNode;
                
                pNode = preNode->next;
                pNew = pNew->next;
            } else {
                preNode = pNode;
                pNode = pNode->next;
            }
        }
        
        pNode = headNode.next;
        if(pNode) {
            pNew->next = pNode;
        }
        return newList.next;
    }
};