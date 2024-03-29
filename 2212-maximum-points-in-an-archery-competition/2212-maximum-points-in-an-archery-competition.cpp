class Solution {
public:
    vector<int> ans;
    int maxSum = 0;
    void getBobArrow(vector<int>& alice, int rem, int sum, vector<int> bob, int pos){
        if(sum >= maxSum && rem >= 0){
            maxSum = sum;
            ans = bob;
        }
        if(pos < 0 || rem < 0) return;
        if(pos !=0){
            getBobArrow(alice,rem,sum,bob, pos-1);
            bob[pos] = alice[pos] + 1;
            getBobArrow(alice,rem-bob[pos],sum+pos,bob, pos-1);
        }
        else{
            bob[pos] = rem;
            if(rem>=alice[pos] + 1){
                sum = sum+pos;
            }
            getBobArrow(alice,0,sum,bob,pos-1);
        }
        
    }
    vector<int> maximumBobPoints(int num, vector<int>& alice) {
        vector<int> bob(12,0);
        getBobArrow(alice,num,0,bob, 11);
        return ans;
    }
};