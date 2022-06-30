class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long ans = LLONG_MAX, prefixSum = 0, totalSum = 0, n = beans.size();
        sort(beans.begin(), beans.end());
        for(int x: beans){
            totalSum += x-beans[0];
        }
        ans = totalSum;
        prefixSum = beans[0];
        for(int i=1; i<n; i++){
            long long diff = beans[i] - beans[i-1];
            totalSum = totalSum  - (diff*(n-i));
            ans = min(ans, prefixSum + totalSum);
            prefixSum += beans[i];
        }
        return ans;
    }
};