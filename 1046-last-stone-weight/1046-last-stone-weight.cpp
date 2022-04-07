class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i: stones) pq.push(i);
        while(pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a>b){
                pq.push(a-b);
            }
            else if(b>a){
                pq.push(b-a);
            } 
        }
        return !pq.empty() ?  pq.top():0;
    }
};