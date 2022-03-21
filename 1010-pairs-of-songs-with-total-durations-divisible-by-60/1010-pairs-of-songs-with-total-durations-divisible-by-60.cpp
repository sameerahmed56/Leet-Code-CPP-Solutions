class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size(), ans =0, count;
        vector<int> vec(60,0);
        for(int curr: time) vec[curr%60]++;
        vec[0]%2==0 ? ans+=(vec[0]/2)*(vec[0]-1) : ans+=((vec[0]-1)/2)*(vec[0]);
        vec[30]%2==0 ? ans+=(vec[30]/2)*(vec[30]-1) : ans+=((vec[30]-1)/2)*(vec[30]);
        for(int i=1;i<=29;i++){
            count= vec[i]*vec[60-i];
            ans += count;
        }
        return ans;
    }
};