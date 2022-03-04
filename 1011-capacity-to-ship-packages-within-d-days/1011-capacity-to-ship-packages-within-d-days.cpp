class Solution {
public:
    bool isFeasible(vector<int>& w, int days, int maxCapacity){
        int count = 0, i = 0, currSum = 0;
        while(i<w.size()){
            if(w[i] > maxCapacity){
                return false;
            }
            currSum+=w[i];
            if(currSum<=maxCapacity)i++;
            else{
                currSum=0;
                count++;
            }
        }
        count = currSum ==0?count:count+1;
        return count<=days;
    }
    int shipWithinDays(vector<int>& w, int days) {
        int sum =accumulate(w.begin(),w.end(),0), l = 1, r=sum, ans = INT_MAX;
        while(l<=r){
            int mid = l + (r - l) / 2;
            if(isFeasible(w,days,mid)){
                r=mid-1;
                ans = min(mid,ans);
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};