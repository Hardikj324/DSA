class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int maxEl = *max_element(costs.begin(),costs.end());
        int count=0;
        vector<int> freq(maxEl+1);
        for(int i:costs){
            freq[i]++;
        }

        for(int i=0;i<=maxEl;i++){
            while(freq[i]>0 && coins>=i){
                count++;
                freq[i]--;
                coins -=i;
            }
        }

        return count;
    }
};