class Solution {
public:
    int minimumDeletions(vector<int>& A) {
        int a = max_element(begin(A), end(A)) - begin(A), b = min_element(begin(A), end(A)) - begin(A), n = A.size();
        int start = min(a, b), end = max(a, b);
        return min({end + 1, n-start, start + n - end + 1});
    }
};