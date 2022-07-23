class Solution {
public:
    bool isPalindrome(string s, int l, int r){
        while(l<r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void palindromePartition(string& s, int start, vector<vector<string>>& ans, vector<string> ds){
        int n = s.size();
        if(start == n){
            ans.push_back(ds);
            return;
        }
        for(int i=start; i<n; i++){
            if(isPalindrome(s,start,i)){
                ds.push_back(s.substr(start,i-start+1));
                palindromePartition(s,i+1,ans,ds);
                ds.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        palindromePartition(s,0,ans,{});
        return ans;
    }
};