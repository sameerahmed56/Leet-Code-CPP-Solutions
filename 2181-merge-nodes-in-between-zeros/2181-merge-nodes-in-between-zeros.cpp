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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* root =  new ListNode(0);
        ListNode* ans = root;
        int sum = 0;
        while(head!= nullptr){
            if(head->val == 0 && sum!=0){
                ListNode* curr = new ListNode(sum);
                root->next = curr;
                root = root->next;
                sum=0;
            }
            else{
                sum+=head->val;
            }
            head = head->next;
        }
        return ans->next;
    }
};