class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mp;
        for(char c: s){
            mp[c]++;
        }    
        priority_queue <int> pq;
        for (auto elem : mp){
            pq.push(elem.second);
        }
        int prev = pq.top(), count = 0;
        pq.pop();
        while(!pq.empty()){
            if(pq.top() == 0){
                pq.pop();
                break;
            }
            if(pq.top() == prev){
                pq.push(prev-1);
                pq.pop();
                count++;
            }
            else{
                prev = pq.top();
                pq.pop();
            }
        }
        return count;
    }
};