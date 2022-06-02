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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int> visited;
        while(headA != NULL) {
            visited[headA] = 1;
            headA = headA->next;
        }
        while(headB != NULL) {
            if(visited[headB] == 1) {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};