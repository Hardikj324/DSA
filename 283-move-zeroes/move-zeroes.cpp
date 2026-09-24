class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();
        int i=0;
        int j=0;

        while(i<=j && j<n){
            if(arr[j]!=0){
                swap(arr[i],arr[j]);
                i++;
            }
            j++;
        }
    }
};