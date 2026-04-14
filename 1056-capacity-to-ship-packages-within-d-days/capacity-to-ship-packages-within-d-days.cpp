class Solution {

    int finddays(vector<int>& weights, int capacity){
        int days = 1;
        int currentLoad = 0;

        for(auto w : weights){
            if(currentLoad + w > capacity){
                days++;
                currentLoad = w;
            }
            else {
                currentLoad += w;
            }
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);

        while(low < high){
            int mid = low + (high - low)/2;

            int needed = finddays(weights,mid);

            if(needed <= days){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};