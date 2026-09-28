class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        map<pair<int,int>, int> mp;
        int count = 0;
        for(int i=1;i<n;i++){
            int x = nums[i-1];
            int y = nums[i];
            if(x!=y){
                mp[{min(x,y),max(x,y)}]++;
            }
            else{
                count++;
            }
        }

        int freq = 0;
        for(auto m:mp){
            freq = max(freq,m.second);
        }

        
        return count + freq;
    }
};