class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int ans = INT_MAX;
        vector<int> best(n,INT_MAX);
        int j=0;
        int curr = 0;
        for(int i=0;i<n;i++){
            curr+=arr[i];
            while(j<=i && curr>target){
                curr-=arr[j];
                j++;
            }
            if(i>0){
               best[i] = best[i-1]; 
            }
            if(curr==target){
                int len = i-j+1;

                if(j>0 && best[j-1]!=INT_MAX){
                    ans = min(ans,len+best[j-1]);
                }

                best[i] = min(len,best[i]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};