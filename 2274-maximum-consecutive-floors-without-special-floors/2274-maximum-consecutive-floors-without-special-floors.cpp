class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int ans = 0, prev = special[0], n = special.size();
        for(int i=1; i<n; i++){
            ans = max(ans,special[i] - prev-1);
            prev = special[i];
        }
        return ans = max({ans,special[0]-bottom, top - special[n-1]});
    }
};