class Solution {
public:
    int largestInteger(int num) {
        int temp = num, ans = 0;
        priority_queue<int> even;
        priority_queue<int> odd;
        while(temp>0){
            if(temp%2==0)even.push(temp%10);
            else odd.push(temp%10);
            temp/=10;
        }
        string s = to_string(num);
        for(auto c: s){
            if((c-'0')%2==0){
                ans = ans*10 + even.top();
                even.pop();
            }
            else{
                ans = ans*10 + odd.top();
                odd.pop();
            }
        }
        return ans;
    }
};