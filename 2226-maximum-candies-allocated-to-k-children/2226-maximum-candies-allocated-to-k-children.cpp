class Solution {
public:
    int isFeasible(vector<int>& candies, long long k, long long mid){
        if(mid==0) return true;
        long long count = 0;
        for(int curr: candies){
            count += curr/mid;
        }
        return count>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long upperBound = 0, sum = 0; 
        for(int curr: candies){
            sum += curr;
            upperBound += sum/k;
            sum = sum%k;
        }
        if(upperBound==0) return 0;
        long long l = 0, r = upperBound;
        int ans = 0;
        while(l<=r){
            long long mid = l + (r-l)/2;
            if(isFeasible(candies,k,mid)){
                ans = mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};