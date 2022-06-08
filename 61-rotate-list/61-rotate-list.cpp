/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int countNode(ListNode* head) {
        int count = 0;
        while(head != NULL) {
            head = head->next;
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        
        int n = countNode(head);
        ListNode* temp = head;
        
        // moving n times a list will result to the same list
        k = k % n;  // (Required)
        if(k == 0) return head;
        
        // move temp to n-k-1 th node
        for(int i=1; i<n-k; i++) {
            temp = temp->next;
        }
        
        // now temp is pointing to node 3 in our example
        ListNode* newHead = temp->next;  // node 4 in our example
        temp->next = NULL; // breaking the link (Important) (Always break the link which is not required, otherwise it may result in a cylce or undefined behaviour)
        
        // take a temp variable and traverse the list with newHead 
        temp = newHead;            // No need to define new variable, we can reuse the same temp variable
        while(temp != NULL && temp->next != NULL) {     // (temp != NULL) check is required while accesing temp->next (Important)
            temp = temp->next;
        }
        // temp is pointing to node 5 in our example
        // append head in the last
        temp ->next = head;
        return newHead;
    }
};