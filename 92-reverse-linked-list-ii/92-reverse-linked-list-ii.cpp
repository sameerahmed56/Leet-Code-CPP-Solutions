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
    ListNode* reverse(ListNode* new_head, ListNode* prev_node, int left, int right)
    {
        ListNode* current = new_head;
        ListNode *prev = nullptr, *next = nullptr;
        for(left ; left <= right; left++) {
            next = current-> next;
            current-> next = prev;
            prev = current;
            current = next;
        }
        if(prev_node)
            prev_node -> next = prev;
        if(current)
            new_head -> next = current;
        
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *new_head = head, *prev_node = nullptr;
        int count = 1;
        for(count= 1; count < left; count++){
            prev_node = new_head;
            new_head = new_head -> next;
        }
        prev_node = reverse(new_head, prev_node, left, right);
        
        return left == 1 ? prev_node : head;
    }
};