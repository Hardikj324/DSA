class Solution {
public:
    int helper(vector<int>& prices,int day,int state,vector<vector<int>> &memo){
        int profit = 0;
        if(day==prices.size()){
            return 0;
        }
        if(memo[day][state]!=-1) return memo[day][state];
    
        if(state==0){
            int buy = helper(prices,day+1,1,memo) -prices[day];
            int dont_buy = helper(prices,day+1,0,memo);

            profit = max(buy,dont_buy);
        }
        else{
            int sell = prices[day] + helper(prices,day+1,0 ,memo);
            int dont_sell =helper(prices,day+1,1,memo);

            profit = max(dont_sell,sell);
        }

        return memo[day][state] = profit;
    }   
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> memo(prices.size()+1,vector<int>(2,-1));
        return helper(prices,0,0,memo);

    }
};