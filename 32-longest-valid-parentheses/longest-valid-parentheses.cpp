class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0;
        int right = 0;
        int max = 0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='(') left++;
            else right++;
            if(left==right){
                int curr = 2*left;
                if(max<curr){
                    max = curr;
                }
            }
            else if(left<right){
                right = 0;
                left = 0;
            }
        }

        left = 0;
        right = 0;

        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')') right++;
            else left++;
            if(left==right){
                int curr = 2*left;
                if(max<curr){
                    max = curr;
                }
            }
            else if(left>right){
                right = 0;
                left = 0;
            }
        }
        return max;
    }
};