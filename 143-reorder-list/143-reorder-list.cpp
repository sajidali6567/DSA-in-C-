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
    void printList(ListNode* head) {
        while(head != NULL) {
            cout << head->val << " ";
            head = head->next;
        }
    }
    int countNode(ListNode* head) {
        int count = 0;
        while(head != NULL) {
            head = head->next;
            count++;
        }
        return count;
    }
    ListNode* reverse(ListNode* head) {
        ListNode *prev = NULL, *temp = head;
        while (temp!=NULL) {
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        int n = countNode(head);
        int firstListSize = n - n/2;   // odd/even in case of odd/even node 
        cout << firstListSize << endl;
        // reverse list after firstListSize
        ListNode* list2 = head;
        for(int i=0;i<firstListSize;i++) {
            ListNode* temp = list2;
            list2 = list2->next;
            if(i == firstListSize-1) {
                temp->next = NULL;
            }
        }
        list2 = reverse(list2);
        printList(head);
        cout << endl;
        printList(list2);
        // merge list1(head) and list2
        ListNode* list1 = head;
        while(list1 != NULL && list2 != NULL) {
            ListNode* temp2 = list2;
            list2 = list2->next;
            ListNode* temp1 = list1;
            list1 = list1->next;
            // Insert temp2 betwenn temp1 and temp1->next
            temp2->next = temp1->next;
            temp1->next = temp2;
        }
    }
};