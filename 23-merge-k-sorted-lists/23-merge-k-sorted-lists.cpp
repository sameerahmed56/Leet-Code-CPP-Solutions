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
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()
#define rep(i, a, n) for (int i = a; i < (n); i++)
typedef tuple<int, int, int> t3;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& a) {
        int k = a.size();
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<ListNode*> idx(k, 0);
        ListNode* ans = new ListNode();
        ListNode* head = ans;
        rep(i, 0, k)
        {
            if(a[i] != NULL){
                pq.push({a[i]->val, i});
                a[i] = a[i]->next;
            }
        }
        while (!pq.empty())
        {
            pii x = pq.top();
            pq.pop();
    
            ListNode* temp = new ListNode(x.ff);
            if(ans != nullptr){
                ans->next = temp;
                ans = ans->next;
            }
            else{
                ans = temp;
            }
            if(a[x.ss] != nullptr){
                pq.push({a[x.ss]->val,x.ss});
                a[x.ss] = a[x.ss]->next;
            }
        }
        return head->next;
    }
};