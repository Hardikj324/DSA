class Solution {
public:
    int helper(int k, vector<int>& prices,int day,int state,vector<vector<vector<int>>> &memo,int transaction){
        if(day == prices.size() || transaction == k) return 0;
        if(memo[day][state][transaction]!=-1) return memo[day][state][transaction];

        int profit = 0;
        if(state==0){
            int buy = helper(k,prices,day+1,1,memo,transaction) -prices[day];
            int dont_buy = helper(k,prices,day+1,0,memo,transaction);

            profit = max(buy,dont_buy);
        }
        else{
            int sell = prices[day] + helper(k,prices,day+1,0 ,memo,transaction+1);
            int dont_sell =helper(k,prices,day+1,1,memo,transaction);

            profit = max(dont_sell,sell);
        }
        return memo[day][state][transaction]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> memo(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return helper(k,prices,0,0,memo,0);
    }       
};