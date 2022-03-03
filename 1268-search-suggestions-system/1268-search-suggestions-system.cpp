class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        string pref = "";
        int n = products.size();
        for(char c: searchWord){
            pref += c;
            vector<string> temp;
            for(string s: products){
                if(pref == s.substr(0,pref.size())){
                    temp.push_back(s);
                }
                if(temp.size() == 3) break;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};