class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int t = 0;
        int b = n-1;
        int l = 0;
        int r = n-1;
        vector<vector<int>> mat (n,vector<int>(n,0));
        int num = 1;
       while(l<=r && t<=b){
        for(int i=l;i<=r;i++){
            mat[t][i] = num;
            num++;
        }
        t++;
        for(int i=t;i<=b;i++){
            mat[i][r] = num;
            num++;
        }
        r--;
        for(int i=r;i>=l;i--){
            mat[b][i] = num;
            num++;
        }
        b--;
        for(int i=b;i>=t;i--){
            mat[i][l] = num;
            num++;
        }
        l++;
       }

       return mat;

    }
};