class Solution {
public:
    bool isSubsequence(string s, string t) {
        int currS = 0, currT = 0;
        while(currT < t.size() && currS <  s.size()){
            if(s[currS] == t[currT++]) currS++;
        }
        return currS == s.size();
    }
};