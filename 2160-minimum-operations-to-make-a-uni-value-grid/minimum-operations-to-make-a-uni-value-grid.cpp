class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        if(n==1 && m==1){
            return 0;
        }
        vector<int> arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            arr.push_back(grid[i][j]);
        }
        }

        sort(arr.begin(),arr.end());

        n=arr.size();
        int mid_value = arr[n/2];
        int total=0;
        for(int i=0;i<n;i++){
        if ((arr[i] - arr[0]) % x != 0) {
            return -1;
        }
        total += abs(arr[i] - mid_value) / x;
        }

        return total;
    }
};