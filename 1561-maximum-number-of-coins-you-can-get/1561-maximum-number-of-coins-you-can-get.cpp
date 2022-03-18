class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size(), sum = 0, curr = n-2;
        sort(piles.begin(),piles.end());
        for(int i =0; i<n/3;i++){
            sum += piles[curr];
            curr-=2;
        }
        return sum;
    }
};