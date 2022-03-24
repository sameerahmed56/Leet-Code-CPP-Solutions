class Solution {
public:
    int numRescueBoats(vector<int>& pep, int limit) {
        int ans = 0, l= 0, r=pep.size()-1;
        sort(pep.begin(),pep.end());
        while(l<=r){
            if(pep[l]+pep[r] <= limit) l++;
            r--;
            ans++;
        }
        return ans;
    }
};