class Solution {
public:
    int strongPasswordChecker(string s) {
        int n = s.size();
        vector<int> g;
        int l= 0;
        for(int i=0; i<=n; i++){
            if(i==n || s[i] != s[l]){
                g.push_back(i-l);
                l =i;
            }
        }
        bool upper = 0, lower =0, num = 0;
        for(char c: s){
            if('a'<=c && c<='z') lower = 1;
            if('A'<=c && c<='Z') upper= 1;
            if('0'<=c && c<='9') num = 1;
            
        }

        int cnt  = lower + upper + num;
        int ans = 0;
        if(n<6){
            for(int x: g){
                if(x>=3){
                    int toAdd = 0;
                    if(x%2==0){
                        toAdd = (x/2) - 1;
                    }
                    else toAdd = (x/2);
                    ans += toAdd;
                    cnt += toAdd;
                    n += toAdd;
                }
            }
            if(cnt<3){
                ans += 3-cnt;
                n += 3-cnt;
            }
            if(n<6) ans += 6-n;
        }
        else if(n>=6 && n<= 20){
            for(int x: g){
                int toAdd = x/3;
                if(x>=3){
                    ans += toAdd;
                    cnt += toAdd;
                }
            }
            if(cnt<3){
                ans += 3-cnt;
            }
        }
        else{
            for(int r=0; r<3; r++){
                bool found = 1;
                while(n>20 && found){
                    found = 0;
                    for(int& x: g){
                        if(x >= 3 && x%3==r && n>20){
                            int ops = min(r+1,n-20);
                            ans += ops;
                            n -= ops;
                            x -= ops;
                            found = 1;
                        }
                    }
                }
            }
            if(n>20){
                ans += n - 20;
            }
            else{
                for(int x: g){
                    int toAdd = x/3;
                    if(x>=3){
                        ans += toAdd;
                        cnt += toAdd;
                    }
                }
            }
            if(cnt<3){
                ans += 3-cnt;
            }
        }
        return ans;
    }
};