class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0, ans = 0;
        for(int i=0; i<k; i++){
            sum += arr[i];
        }
        if(sum/k >= threshold) ans++;
        for(int i=0, j = k; j<arr.size(); i++, j++ ){
            sum = sum + arr[j] - arr[i];
            if(sum/k >= threshold) ans++;
        }
        return ans;
    }
};