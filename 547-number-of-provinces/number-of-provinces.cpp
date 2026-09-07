class Solution {
public:
    void dfs(int node, vector<int> &visited,unordered_map<int,vector<int>> &mp){
        visited[node] = 1;
        for(int nei:mp[node]){
            if (!visited[nei])
                dfs(nei, visited, mp);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>> mp;

        int n = isConnected.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1 && i != j)
                    mp[i].push_back(j);
            }
        }

        vector<int> visited(n,0);
        
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,mp);
                ans++;
            }
        }
        return ans;
    }
};