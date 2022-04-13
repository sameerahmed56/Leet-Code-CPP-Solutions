class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n,-1);
        unordered_map<int,int>mp;
        priority_queue <int, vector<int>, greater<int> > pq;
        for(int i=0;i<n;i++){
            if(rains[i] != 0){
                if(mp.find(rains[i]) != mp.end()){
                    if(pq.empty()) return{};
                    queue <int> temp;
                    bool hasFind = false; 
                    while(!pq.empty()){
                        int x = pq.top();
                        pq.pop();
                        if(!hasFind && x>mp[rains[i]]){
                            ans[x] = rains[i];
                            hasFind = true;
                            break;
                        }
                        else{
                            temp.push(x);
                        }
                    }
                    if(!hasFind) return {};
                    while(!temp.empty()){
                        pq.emplace(temp.front());
                        temp.pop();
                    }
                }
                mp[rains[i]] = i;
            }
            else{
                pq.emplace(i);
                ans[i]=1;
            }
        }
        return ans;
    }
};