class Solution {
public:
    bool isFeasible(vector<int>& bloom_days, int m, int k, int bloom_day) {
        int bouquets = 0, flowers = 0;
        for(int day: bloom_days) {
            if(day <= bloom_day)
                ++flowers;
            else
                flowers = 0;
            if(flowers == k)
                ++bouquets, flowers = 0;
        }
        
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*k>bloomDay.size()){
            return -1;
        }
        int l = 0, r= INT_MAX;
        while(l<r){
            int mid = l + (r - l) / 2;
            if(isFeasible(bloomDay,m,k,mid)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return r;
    }
};