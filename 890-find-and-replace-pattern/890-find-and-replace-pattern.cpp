class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char,int> patMP;
        unordered_map<char,int> wordMP;
        int n= words.size(), m = pattern.size(), pos=0;
        for(int i =0;i<m;i++){
            if(patMP.find(pattern[i]) == patMP.end()){
                patMP[pattern[i]] = pos;
                pos++;
            }
        }
        vector<string> ans;
        for(int i=0;i<n;i++){
            bool isValid = true;
            pos=0;
            for(int j =0;j<m;j++){
                if(wordMP.find(words[i][j]) == wordMP.end()){
                    wordMP[words[i][j]] = pos;
                    pos++;
                }
                if(patMP[pattern[j]] != wordMP[words[i][j]]){
                    isValid = false;
                    break;
                }
            }
            if(isValid) ans.push_back(words[i]);
            wordMP.clear();
        }
        return ans;
    }
};