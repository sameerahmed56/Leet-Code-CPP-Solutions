class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& path) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        int n = path.size();
        for(int i=0; i<n; i++){
            string s = "";
            int j = 0;
            while(path[i][j] != ' ') s+=path[i][j++];
            s+= '/';
            j++;
            string x = "", file = "";
            while(j<path[i].size()){
                if(path[i][j] == '('){
                    file = s + x;
                    x = "";
                }
                else if(path[i][j] == ')'){
                    mp[x].push_back(file);
                }
                else if(path[i][j] == ' '){
                    x ="";
                    file = "";
                }
                else{
                    x += path[i][j];
                }
                j++;
            }
        }
        for(auto it: mp){
            if(it.second.size() > 1){
                ans.push_back(it.second);
            }
        }
        return ans;
    }
};