class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> result;
        int start;
        int end;
        int i=0;
        while(i<n){
            start = nums[i];
            end = nums[i];
            i++;
            while(i < n && nums[i-1]+1==nums[i]){
                end = nums[i];
                i++;
            }

            if(start==end){
                string res = to_string(start);
                result.push_back(res);
            }
            else{
                string res = to_string(start) + "->" + to_string(end);
                result.push_back(res);
            }
        }

        return result;
    }
};