class Solution {
public:
    long long calcTrip(vector<int>& time, long long day) {
        long long trips = 0;
        for(int curr: time) trips += day/curr; 
        return trips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ans = 0;
        int minimum = *min_element(time.begin(),time.end());
        int n = time.size();
        long long  rem = 100000000000000/minimum, newTotal = min(rem,(long long)totalTrips);
        long long l = 1, r = minimum*newTotal;
        while(l<=r){
            long long mid = l + (r-l)/2;
            long long trips = calcTrip(time,mid);
            cout << mid << "-" << trips << " ";
            if( trips >= totalTrips){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
            
        }
        return ans;
    }
};