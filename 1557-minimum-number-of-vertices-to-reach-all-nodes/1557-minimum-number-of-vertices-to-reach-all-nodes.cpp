#pragma GCC optimize("Ofast","inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
static const auto fast = []() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0; } ();
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inorder(n,0), ans;
        for(auto x: edges) inorder[x[1]]++;
        
        for(int i=0;i<n;i++)
            if(inorder[i]==0) ans.push_back(i);
        
        return ans;
    }
};