class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        vector<long long> freq(n,0);
        for(int i=0; i<n; i++){
            freq[edges[i]] = freq[edges[i]] +  i;
        }
        long long mx = 0, ans = 0;
        for(int i=0; i<n; i++){
            if(freq[i] > mx){
                mx = max(mx,freq[i]);
                ans = i;
            }
        }
        return (int)ans;
    }
};