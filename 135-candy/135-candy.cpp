class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size(), ans = 1;
        int i = 1, prev = 1, stack = 1;
        if(n<=1) return n;
        bool isInc = arr[1] > arr[0];
        while(i < n){
            if(arr[i] > arr[i-1] || arr[i] == arr[i-1]){
                arr[i] == arr[i-1] ? prev = 1 : !isInc ? prev = 2 :  prev++; 
                stack = 1;
                ans+=prev;
                isInc = true;
            }
            else{
                stack++;
                stack > prev ? ans += stack : ans += stack - 1;
                isInc = false;
            }
            i++;
        }
        return ans;
    }
};

