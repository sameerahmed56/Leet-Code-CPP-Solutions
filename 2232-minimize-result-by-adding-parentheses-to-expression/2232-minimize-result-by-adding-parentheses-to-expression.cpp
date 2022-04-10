class Solution {
public:
    int calculateValue(string& s,int &plusInd, int left, int right){
        int a=0,b=0,c=0,d=0,n = s.size();
        for(int i=0;i<n;i++){
            if(i<left){
                a=a*10+(s[i]-'0');
            }
            else if(i>=left && i<plusInd){
                b=b*10+(s[i]-'0');
            }
            else if(i<=right && i>plusInd){
                c=c*10+(s[i]-'0');
            }
            else if(i>right){
                d=d*10+(s[i]-'0');
            }
        }
        // cout << a <<"-" << b << "-" << c <<"-" << d << " ";
        a = a == 0?1:a;
        d = d == 0?1:d;
        return a*(b+c)*d;
    }
    string minimizeResult(string expression) {
        int plusInd = 0, n = expression.size(), minVal = INT_MAX, left = 0, right = 0;
        for(int i=0;i<n;i++){
            if(expression[i]=='+'){
                plusInd = i;
                break;
            }
        }
        for(int i=0;i<plusInd;i++){
            for(int j=1;j<n-plusInd;j++){
                int calculatedVal = calculateValue(expression,plusInd,i,plusInd+j);
                if( calculatedVal < minVal){
                    minVal = calculatedVal;
                    left = i;
                    right = plusInd+j+1;
                }
            }
        }
        string ans(n+2, '0');
        for(int i=0;i<left;i++){
            ans[i]=expression[i];
        }
        ans[left] = '(';
        for(int i=left;i<right;i++){
            ans[i+1]=expression[i];
        }
        ans[right+1] = ')';
        for(int i=right;i<n;i++){
            ans[i+2]=expression[i];
        }
        // cout << minVal;
        return ans;
    }
};