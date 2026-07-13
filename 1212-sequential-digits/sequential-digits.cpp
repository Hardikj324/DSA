class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> ans;
        int lenLow = to_string(low).size();
        int lenHigh = to_string(high).size();
                                                //123 234 
        for(int len=lenLow;len<=lenHigh;len++){
            for(int i=0;i+len<=9;i++){
            int num = stoi(digits.substr(i, len));
            if(num >= low && num <= high){
                    ans.push_back(num);
                }
        }
        }
        return ans;
    }
};