class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int i=0;
        int n = colors.size()-1;
        int ans=INT_MIN;
        for(i;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(colors[i]==colors[j]){
                    continue;
                }
                else{
                    int dist = j-i;
                    ans = max(ans,dist);
                }
        }
        }
        return ans;
    }
};