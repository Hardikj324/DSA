class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = INT_MIN;
        int smallest = prices[0];

        for(int i=1;i<n;i++){
            if(smallest<prices[i]){
                ans = max(ans,prices[i] - smallest);
            }
            smallest = min(smallest,prices[i]);
        }

        if(ans==INT_MIN){
            return 0;
        }
        return ans;
    }
};