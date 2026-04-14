class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=0;
        for(auto x:trips){
            n=max(n,x[2]);
        }
        vector<int> sum(n+1,0);
        for(auto x:trips){
            int p = x[0];
            int l=x[1];
            int r=x[2];
            sum[l]+=p;
            sum[r]-=p;
        }
        int current=0;
        for(int i=0;i<=n;i++){
            current +=sum[i];
            if(current>capacity){
                return false;
            }
        }
        return true;
    }
};