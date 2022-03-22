class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        queue<string> q;
        map<string,int> inorder;
        map<string,vector<string>> adj;
        vector<string> ans;
        for(string s: supplies){
            q.push(s);   
        }
        for(int i=0; i< recipes.size();i++){
            for(string str: ingredients[i]){
                inorder[recipes[i]]++;
                adj[str].push_back(recipes[i]);
            }
        }
        
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            for(string s: adj[curr]){
                if(--inorder[s]==0){
                    ans.push_back(s);
                    q.push(s);
                }
            }
        }
        return ans;
    }
};