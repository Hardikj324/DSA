class Solution {
public:
    int helper(vector<int>& prices,int fee,int day,int state,vector<vector<int>> &memo){
        int profit = 0;
        if(day==prices.size()){
            return 0;
        }
        if(memo[day][state]!=-1){
            return memo[day][state];
        }

        if(state==0){
            int buy = helper(prices,fee,day+1,1,memo) -prices[day];
            int dont_buy = helper(prices,fee,day+1,0,memo);

            profit = max(buy,dont_buy);
        }
        else{
            int sell = prices[day] + helper(prices,fee,day+1,0 ,memo)-fee;
            int dont_sell =helper(prices,fee,day+1,1,memo);

            profit = max(dont_sell,sell);
        }

        return memo[day][state] = profit;

    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> memo(prices.size()+1,vector<int>(2,-1));
        return helper(prices,fee,0,0,memo);
    }
};