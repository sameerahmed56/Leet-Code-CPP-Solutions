class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> st(27,0); 
        vector <int> ans;
        vector<vector<int>> vec;
        string temp = "";
        for(int i = 0; i < n; i++){
            if (st[s[i] - 'a'] == 0) {
                st[s[i] - 'a'] = 1;
                bool noDuplicate = true;
                for(int j = n-1; j >i;j--){
                    if(s[i] == s[j]){
                        noDuplicate = false;
                        vec.push_back({i,j});
                        break;
                    }
                }
                if(noDuplicate){
                    vec.push_back({i,i});
                }
            }
        }
        int k = 0;
        while(k < vec.size()){
            int start = vec[k][0];
            int end = vec[k][1];
            while(k < vec.size() && end >= vec[k][0]){
                end = max(vec[k][1],end);
                k++;
            } 
            ans.push_back(end-start + 1);
        }
        return ans;
    }
};