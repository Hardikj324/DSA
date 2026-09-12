class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        vector<int> freq(10, 0);
    for (int d : digits)
        freq[d]++;

    for(int i=100;i<=999;i+=2){
        vector<int> vec(10,0);
        int x = i;

        vec[x%10]++;
        x/=10;

        vec[x%10]++;
        x/=10;

        vec[x]++;

        bool ispos = true;
        for(int j=0;j<10;j++){
            if(vec[j]>freq[j]){
                ispos = false;
                break;
            }
        }
        if(ispos){
            ans.push_back(i);
        }
    }
    return ans;
    }
};