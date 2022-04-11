class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        long long sum = 0, ans = 1;
        int count =0, n=nums.size();
        priority_queue<int>pq;
        for(int a: nums){
            sum+=a;
            pq.push(a);
        }
        sum+=k;
        int div = 0;
        while(!pq.empty()){
            div = sum/n;
            int x = pq.top();
            // cout << div << "-" << x << " ";
            pq.pop();
            if(x<div || n==1){
                if(k<div-x || n==1){
                    x+=k;
                    k=0;
                }
                else{
                    k-=div-x;
                    x+=div-x;
                }
            }
            ans *=x;
            ans = ans%1000000007;
            sum-=x;
            n--;
        }
        return (int)ans;
    }
};