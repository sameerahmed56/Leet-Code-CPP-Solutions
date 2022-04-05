class Solution {
public:
    vector<int> ans;
    void createDigits(int low, int high, int num) {
        if(num>high) return;
        if(num>=low) ans.push_back(num);
        int lastDigit = num%10;
        if(lastDigit != 9){
            num = (num*10) + (lastDigit+1);
            createDigits(low,high,num);
        }
    }

    vector<int> sequentialDigits(int low, int high) {
        for(int i=1;i<=9;i++){
            createDigits(low,high,i);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};