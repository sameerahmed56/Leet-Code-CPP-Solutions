class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visi(n,false);
        queue<int>q;
        q.push(0);
        visi[0] = true;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i=0;i<rooms[x].size();i++){
                if(!visi[rooms[x][i]]){
                    visi[rooms[x][i]] = true;
                    q.push(rooms[x][i]);
                }
            }
        }
        for(bool b: visi){
            if(!b) return false;
        }
        return true;
    }
};