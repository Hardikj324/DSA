class Solution {
public:
   typedef pair<int,int> p;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        int n = arrival.size();
        int t = 0;

        set<int> servers;
        priority_queue<p,vector<p>,greater<p>> busy;

        for(int i=0;i<k;i++){
            servers.insert(i);
        }

        vector<int> res(k,0);

        for(int i=0;i<n;i++){
            int ar = arrival[i];
            int lo = load[i];

            t = ar;

            while(!busy.empty() && busy.top().first<=t){
                int ser = busy.top().second;
                busy.pop();
                servers.insert(ser);
            }

            int target = i%k;
            auto it = servers.lower_bound(target);

            if(it==servers.end()){
                it = servers.begin();
            }

            if(servers.empty()){
                continue;
            }
            int ser = *it;
            busy.push({t+lo,ser});
            servers.erase(ser);

            res[ser]++;

        }
        
        int maxi = *max_element(res.begin(),res.end());
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(res[i]==maxi)
                ans.push_back(i);
        }

        return ans; 
    }
};