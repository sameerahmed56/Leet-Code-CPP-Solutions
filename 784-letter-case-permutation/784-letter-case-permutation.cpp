class Solution {
public:
    vector<string> ans;
    void permutate(string curr,string s, int i){
        if(i>=s.size()){
            ans.push_back(curr);
            return;
        }
        if(isdigit(s[i])){
            curr.push_back(s[i]);
            permutate(curr,s,i+1);
        }
        else{
            string c1 = curr;
            c1.push_back(toupper(s[i]));
            permutate(c1,s,i+1);
            string c2 = curr;
            c2.push_back(tolower(s[i]));
            permutate(c2,s,i+1);
            
        }
    }
    vector<string> letterCasePermutation(string s) {
        permutate("",s,0);
        return ans;
    }
};