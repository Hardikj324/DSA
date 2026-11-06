class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int q = queries.size();
        int l = logs.size();
        vector<pair<int,int>> qu(q,{0,0});

        for(int i=0;i<q;i++){
            qu[i] = {queries[i],i};
        }
        sort(qu.begin(),qu.end());
        sort(logs.begin(),logs.end(),[](auto &a, auto &b){
            return a[1]<b[1];
        });
        vector<int> res(q,0);
        unordered_map<int,int> freq;

        int left = 0;
        int right = 0;
        int activeServers = 0;
        for(int i=0;i<q;i++){
            int up = qu[i].first;
            int lo = qu[i].first - x;
            int index = qu[i].second;

            while(right<l && logs[right][1]<=up){
                if(freq[logs[right][0]] == 0){
                    activeServers++;
                }
                freq[logs[right][0]]++;
                right++;
            }

            while(left<right && logs[left][1]<lo){
                freq[logs[left][0]]--;
                if(freq[logs[left][0]]==0){
                    activeServers--;
                }
                left++;
            }

            res[index] = n - activeServers;
        } 

        return res;

    }
};