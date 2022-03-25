// class Solution {
// public:
//     string getSmallestString(int n, int k) {
//         string ans = "";
//         string alp = "0abcdefghijklmnopqrstuvwxyz";
//         for(int i=26; i >= 1; i--){
//             while(k-i>=n-1 && n>0 && k>0){
//                 // cout << times << "-" << alp[i] << " ";
//                 k -= i;
//                 ans = string(1,'a') + ans;
//                 n--;
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans =  string(n,'a');
        k-=n;
        for(int i=n-1; i >= 0; i--){
            int curr = min(k,25);
            ans[i] +=  curr;
            k-=curr;
        }
        return ans;
    }
};