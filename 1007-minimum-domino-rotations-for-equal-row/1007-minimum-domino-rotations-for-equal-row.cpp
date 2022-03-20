class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int> mp;
        int n=tops.size(), freq = INT_MIN, elem = 0;
        for(int i=0;i<n;i++){
            if(tops[i] == bottoms[i]){
                mp[tops[i]]++;
                if(mp[tops[i]] > freq){
                    elem = tops[i];
                    freq = mp[tops[i]];
                }
            }
            else{
                mp[tops[i]]++;
                if(mp[tops[i]] > freq){
                    elem = tops[i];
                    freq = mp[tops[i]];
                }
                mp[bottoms[i]]++;
                if(mp[bottoms[i]] > freq){
                    elem = bottoms[i];
                    freq = mp[bottoms[i]];
                }
            }
        }
        int tp=0,bt=0;
        for(int i=0;i<n;i++){
            if(tops[i] != elem && bottoms[i] != elem) return -1;
            if(tops[i]!=elem)tp++;
            if(bottoms[i]!=elem)bt++;
        }
        return min(tp,bt);
    }
};