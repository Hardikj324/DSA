class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();
        int j=0;
       int i=0;
       while(i<n && j<n){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
        i++;
       }
    }
};