class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
         unordered_set<int> st;
        vector<int> win_team;

        for (int i = 0; i < edges.size(); i++) {
            st.insert(edges[i][1]);   
        }

        for (int i = 0; i < n; i++) {
            if (st.find(i) == st.end()) {
                win_team.push_back(i);
            }
        }

        if (win_team.size() > 1) {
            return -1;
        }
        return win_team[0];
    }
};