class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper = 0;
        int lower=0;
        for(auto s:word){
            if(int(s)>=97 && int(s)<=122){
                lower++;
            }
            if (int(s) >= 65 && int(s) <= 90) {
                upper++;
            }

        }

        if(lower!=0 && upper!=0){
            if(isupper(word[0]) && lower!=0 && upper==1){
                return true;
            }
            return false;
        }
        else{
            return true;
        }
    }
};