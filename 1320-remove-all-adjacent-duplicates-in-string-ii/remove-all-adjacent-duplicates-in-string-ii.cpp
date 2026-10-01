class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        int n = s.size();

        for(int i=0;i<n;i++){
            if(!st.empty() && st.top().first == s[i]){
                if(st.top().second==k-1){
                    while( !st.empty() && st.top().first == s[i]){
                        st.pop();
                    }
                }
                else{
                    st.push({s[i],st.top().second + 1});
                }
            }
            else{
                st.push({s[i],1});
            }
        }

        string str = "";
        n = st.size();
        for(int i=0;i<n;i++){
            str.push_back(st.top().first);
            st.pop();
        }
        reverse(str.begin(),str.end());

        return str;
    }
};