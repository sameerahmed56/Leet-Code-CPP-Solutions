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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr;
        ListNode* prev;
        ListNode* perf;
        curr = head;
        prev = head;
        int i = 0;
        while(curr ){
            if(curr -> next){
                if(i == 0){
                    if(curr -> val < curr -> next -> val ){
                        head = curr;        
                        perf = head;
                        break;
                    }
                    else{
                        head = nullptr;
                    }
                    i++;
                }
                else{
                    if(curr -> val < curr -> next -> val && curr -> val > prev -> val){
                        head = curr;
                        perf = head;
                        break;
                    }
                    else{
                        head = nullptr;
                    }
                }
            }
            else{
                if(i == 0){
                    return head;
                }
                else{
                    if(curr -> val > prev -> val){
                        head = curr;
                        perf = head;
                        break;
                    }
                }
            }
            prev = curr;
            curr = curr -> next;
        }
        prev = curr;
        while(curr){
            if(curr -> next == nullptr){
                cout << curr -> val << endl;
                if(curr -> val > prev -> val){
                    perf -> next = curr;
                    perf = perf -> next;
                    cout << perf -> val << endl;
                }
            }
            else{
                 if(curr -> val < curr -> next -> val && curr -> val > prev -> val){
                    perf -> next = curr;
                    perf = perf -> next;
                    cout << perf -> val << endl;
                }
            }
            prev = curr;
            curr = curr -> next;
        }
        if(perf){
            perf -> next  = nullptr;
        }
        return head;
    }
};