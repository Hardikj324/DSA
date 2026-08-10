class Solution {
public:
    vector<int> isPerfectsquare(int n){
        vector<int> arr;
        if(n==1) arr.push_back(n);
        for(int i=1;i<n;i++){
            if(i*i<=n){
                arr.push_back(i*i);
            }
            else{
                break;
            }

        }

        return arr;
    }

    bool solver(int n, vector<int>& sq, vector<int>& dp) {
        if(n==0){
            return false;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        for(int i=0;i<sq.size();i++){
            if (sq[i] > n) {
                break;
            }

            if (solver(n - sq[i], sq, dp) == false) {
                return dp[n] = true;
            }

        }

        return dp[n]=false;
    }



    bool winnerSquareGame(int n) {
        vector<int> sq = isPerfectsquare(n);
        vector<int> dp(n + 1, -1);
        return solver(n,sq,dp);
    }
};