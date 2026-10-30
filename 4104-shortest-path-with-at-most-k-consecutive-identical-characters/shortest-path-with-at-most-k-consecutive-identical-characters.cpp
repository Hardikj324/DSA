class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int,vector<vector<int>>> mp;                
        for(int i=0;i<edges.size();i++){                         
            mp[edges[i][0]].push_back({edges[i][1],edges[i][2]}); 
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> vec(n,vector<int>(k+1,INT_MAX));      
        pq.push({0,0,1});
        vec[0][1] = 0;                                            
        while(!pq.empty()){

            int d = pq.top()[0];
            int u = pq.top()[1];
            int c = pq.top()[2]; 
            pq.pop();

            if(d>vec[u][c]){                                     
                continue;
            }
            for(auto x:mp[u]){
                int count = c;
                if(labels[x[0]] == labels[u]){                    
                    count++;
                }
                else{
                    count = 1;
                }

                if(count>k){
                    continue;
                }

                if(d+x[1]<vec[x[0]][count]){                     
                    vec[x[0]][count] = d+x[1];
                    pq.push({vec[x[0]][count], x[0], count});
                }
            }
        }

        int ans = INT_MAX;                                        
        for(int i=1;i<=k;i++){
            ans = min(ans, vec[n-1][i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};