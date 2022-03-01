class Solution {
public:
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        
    long long int l = time[0];
    for(long long int x: time) l  = min(l, x);
    long long int r = l * totalTrips; 
        
    while (l < r) {
        long long m = (l + r) / 2, trips = 0;
        for (int t : time)
            trips += m / t;
        if (trips < totalTrips)
            l = m + 1;
        else
            r = m;
    }
    return l;
}
};