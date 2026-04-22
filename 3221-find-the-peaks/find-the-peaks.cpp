class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        int n = mountain.size();
        vector<int> arr={};
        for(int i = 1;i<n-1;i++){
                if(mountain[i-1]<mountain[i] && mountain[i]>mountain[i+1]){
                    arr.push_back(i);
                }}
        return arr;
    }
};