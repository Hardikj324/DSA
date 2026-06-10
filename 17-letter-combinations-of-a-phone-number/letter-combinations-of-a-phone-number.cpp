class Solution {
public:
unordered_map<char, string> phoneMap = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};
vector<string> arr;
    void solver(string digits,int i,string curr){
        if(i==digits.size()){
            arr.push_back(curr);
            return ;
        }
        for(char x:phoneMap[digits[i]]){
        curr += x;
        solver(digits,i+1,curr);
        curr.pop_back();
        }
        


    }
    vector<string> letterCombinations(string digits) {
    solver(digits,0,"");
    return arr;
    }

};