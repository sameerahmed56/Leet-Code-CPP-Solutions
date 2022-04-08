class Solution {
public:
    bool isFeasible(vector<int>& nums, int threshold,double mid){
        int count = 0;
        for(int i: nums){
            double x = i;
            count += ceil(x/mid);
        }
        return count <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,r=1e6, ans = 0;
        while(l<=r){
            double mid = l + (r-l)/2;
            if(isFeasible(nums,threshold,mid)){
                r=mid-1;
            }
            else l=mid+1;
        }
        return l;
    }
};