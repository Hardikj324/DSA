class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector <int> arr(n+1,0);
        vector <int> result(n);
        int count = 0;
        for(int i=0;i<n;i++){
            arr[A[i]]++;
            if(arr[A[i]] == 2)
                count++;
            
            arr[B[i]]++;
            if(arr[B[i]] == 2)
                count++;
            
            result[i] = count;
        }
        return result;
    }
};