class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0, count1 = 1;
        while(total/(count1*cost1) > 0){
            long long rem = total-(count1*cost1);
            ans += (rem/cost2) + 1;
            count1++;
        }
        ans+= (total/cost2) + 1;
        return ans;
    }
};