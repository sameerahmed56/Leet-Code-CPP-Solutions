class Solution {
public:
    static bool compSort(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[1] > v2[1];
    }    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compSort);
        int n = boxTypes.size(), i =0, ans = 0;
        while(truckSize > 0 && i<n ){
            if(boxTypes[i][0] <= truckSize){
                truckSize -= boxTypes[i][0];
                ans += boxTypes[i][0]* boxTypes[i][1];
            }
            else{
                ans += truckSize * boxTypes[i][1];
                truckSize = 0;
            }
            i++;
        }
        return ans;
    }
};