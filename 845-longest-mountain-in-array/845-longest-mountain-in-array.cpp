class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size(), ans = 0, currCount = 0, prev = arr[0];
        if(n < 3) return 0;
        bool reachedPeak = false;
        for(int i =1; i < n; i++){
            if(arr[i] > prev){
                if(reachedPeak) currCount=0;
                reachedPeak = false;
                currCount++;
            }
            else if(arr[i] < prev && currCount != 0 ){
                reachedPeak = true;
                currCount++;
                ans = max(currCount, ans);
            }
            else{
                currCount = 0;
                reachedPeak = false;
            }
            prev = arr[i];
        }
        return ans != 0 ? ans+1 : 0;
    }
};