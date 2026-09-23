class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        int count = 0;
        int maxi = 0;
        st.push(-1);
        int i = 0;
        while(i<n){
            char b = s[i];
            if(b=='('){
                st.push(i); 
            }
            else{
                st.pop();

                if(st.empty()){
                    st.push(i);
                }
                else{
                    count = i - st.top();
                    maxi = max(maxi,count);
                }
            }
            i++;
        }

        return maxi;
    }
};