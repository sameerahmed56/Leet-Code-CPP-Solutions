class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> mp;
        int n=fruits.size(), ans = 0,start = 0, i = 0;
        while(i<n){
            mp[fruits[i]]++;
            if(mp.size() > 2){
                while(start < i && mp.size()>2 ){
                    mp[fruits[start]]--;
                    if(mp[fruits[start]]<=0)mp.erase(fruits[start]);
                    start++;
                }
            }
            ans = max(i-start + 1,ans);
            i++;
        }
        return ans;
    }
};