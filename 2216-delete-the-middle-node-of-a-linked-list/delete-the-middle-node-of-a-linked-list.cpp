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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL){
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;

            if(fast->next != NULL){
                fast = fast->next;
            }
        }

        ListNode* prev = head;
        
        while(prev->next != slow){
            prev = prev->next;
        }

        prev->next = slow->next;

        slow->next = NULL;

        return head; 
    }
};