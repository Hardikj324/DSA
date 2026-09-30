class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;

        for(int i=0;i<s.size();i++){
            if(!st.empty() && st.top()==s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string str = "";
        int n = st.size();
        for(int i=0;i<n;i++){
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};