class Solution {
public:
    bool is_Plaindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
    }

    void helper(string s,vector<string> arr,vector<vector<string>>& ans){
        if(s.size()==0){
            ans.push_back(arr);
            return ;
        } 

        for(int i=0;i<s.size();i++){
            string temp=s.substr(0,i+1);
            if(is_Plaindrome(temp)){
                arr.push_back(temp);
                helper(s.substr(i+1),arr,ans);
                arr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> arr;
        helper(s,arr,ans);
        return ans;
    }
};