class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n = s.size();

        for(int i=0;i<n;i++){
            if(s[i]=='(')
                st.push(i);
            else if(s[i]==')'){
                int lastp = st.top();
                st.pop();
                reverse(s.begin()+lastp+1,s.begin() + i);
            }
        }
        
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i]!='(' && s[i]!=')'){
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};