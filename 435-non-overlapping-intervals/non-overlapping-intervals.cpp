class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1]; 
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int count = 0;
        int lastMeet = INT_MIN;
        int n = intervals.size();
        for(int i=0;i<n;i++){
            if(lastMeet<=intervals[i][0]){
                count++;
                lastMeet = intervals[i][1];
            }
        }
        return n - count;
    }
};