class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> count(26,0);
        int dist_count = 0;
        for(int i = 0;i<n;i++){
            if(count[word[i]-'a']==0){
                dist_count++;
            }
            count[word[i]-'a']++;
        }
        sort(count.begin(),count.end(),greater<int>());

        int ans = 0;
        for(int i=0;i<dist_count;i++){
            if(i<=7){
                ans +=  count[i]*1;
            }
            else if(i<=15){
                ans +=  count[i]*2;
            }
            else if(i<=23){
                ans +=  count[i]*3;
            }
            else{
                ans +=  count[i]*4;
            }
        }

        return ans;
    }
};


