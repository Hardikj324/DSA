class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int n = arr1.size();
        int ans = 0;

        for(int i = 0;i<n;i++){
            int num = arr1[i];
            auto lb = lower_bound(arr2.begin(),arr2.end(),num-d);
            
            if(arr2.end()==lb || *lb >num+d){
                ans++;
            }
        }
        return ans;
    }
};