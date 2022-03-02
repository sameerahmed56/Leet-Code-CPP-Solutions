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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return NULL;
        ListNode* less = NULL;
        ListNode* startLess = NULL;
        ListNode* more = NULL;
        ListNode* startMore = NULL;
        while(head != NULL){
            if(head->val < x){
                if(startLess == NULL){
                    less = head;
                    startLess = head;
                }
                else{
                    less->next = head;
                    less = less->next;
                }
            }
            else{
                if(startMore == NULL){
                    more = head;
                    startMore= head;
                }
                else{
                    more->next = head;
                    more = more->next;
                }
            }
            head = head->next;
        }
        if(startLess != NULL){
            if(startMore != NULL){
                less->next = startMore;
                more->next = NULL;
            }
            else{
                less->next = NULL;
            }
            return startLess;
        }
        more->next =  NULL;
        return startMore;
    }
};