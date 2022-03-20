class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map <string, int> mp;
        for(string i: arr) mp[i]++;
        for(string i: arr){
          if(mp[i]==1) k--;
          if(k==0) return i;
        }
        return "";
    }
};