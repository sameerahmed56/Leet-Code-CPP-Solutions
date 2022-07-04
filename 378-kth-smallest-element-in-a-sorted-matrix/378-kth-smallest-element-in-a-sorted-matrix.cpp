class Solution {
public:
    struct compare{
        bool operator() (const tuple <int,int,int>& a, const tuple <int,int,int>& b) {
            return get<0>(a) > get<0>(b);
        };
    };
    int kthSmallest(vector<vector<int>>& A, int k) {
        int n = A.size(), count = 1;
        priority_queue <tuple <int,int,int>, vector<tuple <int,int,int>>, compare > pq;
        for(int j=0; j<n; j++){
            pq.push(make_tuple(A[0][j],0,j));
            A[0][j] = INT_MAX;  
        }
        while(!pq.empty()){
            if(count == k) return get<0>(pq.top());
            int x = get<1>(pq.top());
            int y = get<2>(pq.top());
            pq.pop();
            if(x<n-1 && A[x+1][y] < INT_MAX){
                pq.push(make_tuple(A[x+1][y],x+1,y));
                A[x+1][y] = INT_MAX;
            }
            count++;
        }
        return 0;
    }
};