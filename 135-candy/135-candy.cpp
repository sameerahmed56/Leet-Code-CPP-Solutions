class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size(), ans = 1;
        int i = 1, prev = 1, stack = 1;
        if(n<=1) return n;
        bool isInc = arr[1] > arr[0];
        while(i < n){
            if(arr[i] > arr[i-1]){
                !isInc ? prev = 2 : prev++; 
                stack = 1;
                ans+=prev;
                isInc = true;
            }
            else if(arr[i] == arr[i-1]){
                prev = 1;
                ans += prev;
                isInc = true;
                stack = 1;
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

// [1,2,2,2,2,2,3,4,5,6,7,8,7,6,5,4,3,2,1,0,0,1,5,6,8,1]
// [1,2,1,1,1,1,2,3,4,5,6,7,6,5,4,3,2,1,1,2,3,4,1]
// [1,3,4,5,6,7,9,12,16,21,27,34,6,5,4,3,2,1,2,3,4,1]

