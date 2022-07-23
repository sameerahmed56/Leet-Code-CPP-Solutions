class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.size(), currMax = INT_MIN, currMaxPos = -1;
        vector<pair<int,int>> maxTillPos(n);
        for(int i=n-1; i>=0; i--){
            if(str[i] - '0' > currMax){
                currMax = str[i]-'0';
                currMaxPos = i; 
            }
            maxTillPos[i] = {currMaxPos,currMax};
        }
        for(int i=0; i<n; i++){
            if(maxTillPos[i].first != i && maxTillPos[i].second != str[i]-'0'){
                swap(str[i],str[maxTillPos[i].first]);
                break;
            }
        }
        return stoi(str);
    }
};