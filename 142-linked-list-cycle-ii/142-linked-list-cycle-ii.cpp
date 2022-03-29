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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr){
            return NULL;
        }
        ListNode* fast = head; 
        ListNode* slow = head; 
        bool hasCycle = false;
        while(fast != nullptr && fast -> next != nullptr){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow){
                hasCycle = true;
                break;
            }
        }
        if(!hasCycle) return NULL;
        slow = head;
        while(slow!= fast ){
            fast = fast -> next;
            slow = slow -> next;
        }
        return slow;
    }
};