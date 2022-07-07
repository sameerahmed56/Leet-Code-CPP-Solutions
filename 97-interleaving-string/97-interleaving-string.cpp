class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length()) return false;
         vector<bool> table(s2.length()+1, false);
        for(int i=0; i<s1.length()+1; i++){
            for(int j=0; j< s2.length()+1; j++){
                if(i == 0 && j==0)
                    table[j] = true;
                else if(i == 0)
                    table[j] = (table[j-1] && s2[j-1] == s3[i+j-1]);
                else if(j == 0)
                    table[j] = ( table[j] && s1[i-1] == s3[i+j-1]);
                else
                    table[j] = (table[j] && s1[i-1] == s3[i+j-1] ) || (table[j-1] && s2[j-1] == s3[i+j-1] );
            }
        }
        return table[s2.size()];
    }        
};
// false false false false 