class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long cost = min(cost1+cost2,costBoth);
        long long need = min(need1,need2);
        long long rem = abs(need1-need2);
        
        long long ans = 0;

        ans += cost*need;

        if(rem!=0){
            if(need1>need2){
                ans+= rem*min(costBoth,cost1);
            }
            else{
                ans+= rem*min(costBoth,cost2);
            }
        }

        
        return ans;
    }
};