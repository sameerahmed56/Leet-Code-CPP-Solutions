class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        for(int x: position){
            if(x%2==0) even++;
            else odd++;
        }
        return min(odd,even);
    }
};