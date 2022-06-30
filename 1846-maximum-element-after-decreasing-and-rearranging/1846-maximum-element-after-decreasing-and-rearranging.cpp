class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size(), ans = 1, prevInd = 0;
        sort(arr.begin(),arr.end());
        if(arr[0] != 1){
            arr[0] = 1;
        }
        for(int i=1; i<n; i++){
            if(abs(arr[i] - arr[prevInd]) > 1){
                arr[i] = arr[prevInd] + 1;
            }
            prevInd = i;
            ans = max(ans,arr[i]);
        }
        return ans;
    }
};