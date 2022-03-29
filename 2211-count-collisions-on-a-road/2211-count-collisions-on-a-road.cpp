class Solution {
public:
    int countCollisions(string d) {
        int n = d.size(), ans = 0; 
        bool foundNotLeft = false,foundNotRight = false;
        for(int i=0; i<n;i++){
            if(d[i]== 'R' || d[i] == 'S'){
                foundNotLeft = true;
            }
            else if(foundNotLeft) ans++;
            
            if(d[n-i-1]== 'L' || d[n-i-1] == 'S'){
                foundNotRight = true;
            }
            else if(foundNotRight) ans++;
        }
        return ans;
    }
};