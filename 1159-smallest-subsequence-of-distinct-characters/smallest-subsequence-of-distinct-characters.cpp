class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char>st;
        vector<bool>seen(26,false);
        vector<int>lastocc(26,-1);
        int n = s.size();

        for(int i=0;i<n;i++){
            lastocc[s[i]-'a'] = i;
        }
        
        for(int i=0;i<n;i++){
            if(seen[s[i]-'a'])continue;

            while(!st.empty() && st.top()>s[i] && lastocc[st.top()-'a'] > i ){
                seen[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            seen[s[i]-'a']=true;
        }
        string res="";
        while(!st.empty()){
                res+=st.top();
                st.pop();
        }
        reverse(res.begin(),res.end());

        return res;
    }
};