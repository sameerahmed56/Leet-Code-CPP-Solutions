class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int res = 0, n = s.size();
        for(int i = 0; i < n ; i++){
            int j = i, sum = 0, max_cost = cost[i];
            while(s[j] == s[i]){
                sum += cost[j];
                max_cost = max(max_cost, cost[j]);
                j++;
            }
            if(j > i){
                res += sum - max_cost;
                i = j - 1;
            }
        }
        return res;
    }
};