class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        bool isEven = intLength %2==0;
        long long semilength = isEven ? intLength/2 : intLength/2+1;
        long long n = queries.size();
        vector<long long> ans;
        long long left = 1;
        for(long long i =1;i<semilength;i++) left=left*10;
        for(long long i=0;i<n;i++){
            long long curr =  left + queries[i] - 1;
            string str = to_string(curr);
            long long size = str.size();
            if( size == semilength){
                for(long long i =1; isEven ? i<=semilength : i<semilength;i++) curr=curr*10;
                string rev = string(str.rbegin(),str.rend());
                if(!isEven)rev.erase(0,1);
                stringstream ss;  
                ss << rev;  
                long long reversedLong;
                ss >> reversedLong;
                if(rev.size() > 0){
                    ans.push_back(curr + reversedLong);
                }
                else{
                    ans.push_back(curr);
                }
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};