class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> sum(n,0);
        for(auto x:bookings){
            int l=x[0];
            int r=x[1];
            int b=x[2];

            sum[l-1]+=b;
            if(r<n){sum[r]-=b;}
        }
        vector<int> ans(n,0);
        for(int i=1;i<n;i++){
            sum[i]+=sum[i-1];
        }
        return sum;
    }
};