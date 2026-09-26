class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec(rowIndex+1,1);

        for(int i=1;i<=rowIndex;i++){
            vec[i] = (long long) vec[i-1] * (rowIndex-i+1)/i;
        }

        return vec;
    }
};