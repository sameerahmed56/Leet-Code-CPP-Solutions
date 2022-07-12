class Solution {
public:
    bool dfs(vector<int>& sidesLength, vector<int>& matches, int index, const int target){
        if(index == matches.size())
            return sidesLength[0] == sidesLength[1] && sidesLength[1] == sidesLength[2] && sidesLength[2] == sidesLength[3];
        for (int i = 0; i < 4; ++i) {
            if (sidesLength[i] + matches[index] > target) 
                continue;
            int j = i;
            while (--j >= 0) 
                if (sidesLength[i] == sidesLength[j]) 
                    break;
            if (j != -1) continue;
            sidesLength[i] += matches[index];
            if (dfs(sidesLength, matches, index + 1, target))
                return true;
            sidesLength[i] -= matches[index];
        }
        return false;
    }
    bool makesquare(vector<int>& M) {
        int perimeter = accumulate(M.begin(),M.end(),0);
        int n = M.size();
        if(perimeter%4 !=0 || n < 4) return false;
        sort(M.begin(), M.end(), [](const int &l, const int &r){return l > r;});
        vector<int> sidesLength(4, 0);
        return dfs(sidesLength, M, 0,  perimeter/ 4);
    }
};