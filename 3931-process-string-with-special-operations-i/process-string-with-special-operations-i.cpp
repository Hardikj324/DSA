class Solution {
public:

    string processStr(string s) {
        int n = s.size();
        string result="";
        char last;
        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                result +=result;
            }
            else if(s[i]=='%'){
                reverse(result.begin(),result.end());
            }
            else if(s[i]=='*'){
                if (!result.empty()) {
                    result.pop_back();
                }
            }
            else{
                result.push_back(s[i]);
            }
        }
        return result;
    }
};