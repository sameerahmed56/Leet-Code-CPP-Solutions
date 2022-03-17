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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i: nums){
            mp[i] = 1;
        }
        int ans = 0;
        while(head){
            bool hasGroup = false;
            while(head && mp[head->val] == 1){
                hasGroup = true;
                head=head->next;
            }
            if(hasGroup) ans++;
            if(head) head=head->next;
        }
        return ans;
    }
};