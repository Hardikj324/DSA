class Solution {
public:
    int solver(int n, vector<int>& costs, int i,vector<int>& memo) {
        if(i == n) {
            return 0;
        }

        if(memo[i]!=-1) {
            return memo[i];
        }

        int cost = INT_MAX;
        int j = i+1;
        if(j<=n){
            cost = min(solver(n,costs,j,memo) + costs[j-1] + 1,cost);
        }

        j++;
        if(j<=n){
            cost = min(solver(n,costs,j,memo) + costs[j-1] + 4, cost);
        }

        j++;
        if(j<=n){
            cost = min(solver(n,costs,j,memo) + costs[j-1] + 9, cost);
        }

        return memo[i]=cost;
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> memo(n+1,-1);
        return solver(n, costs, 0,memo);
    }
};