class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        map<int,int> mp;
        for(string s: timePoints){
            int h = (s[0] - '0') * 10 + (s[1] - '0');
            int m = (s[3] - '0') * 10 + (s[4] - '0');
            h = (h*60) + m;
            mp[h]++;
            if(h<720){
                mp[h+1440]++;
            }
        }
        auto it = mp.begin();
        int ans = INT_MAX, prev = it->first;
        if(it->second> 1) return 0;
        for( it=mp.begin(); it!=mp.end();it++){
            if(it==mp.begin()) continue;
            if(it->second>1) return 0;
            ans = min(ans,it->first-prev);
            prev = it->first;
        }
        return ans;
    }
};