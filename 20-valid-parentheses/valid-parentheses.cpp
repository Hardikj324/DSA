class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        
        for(char c:s){
            
            if(c=='['||c=='('||c=='{'){
                st.push(c);
            }
            else if(!st.empty()){
            if(c==')' && st.top()!='('){
                return false;
            }
            else if(c==']' && st.top()!='['){
                return false;
            }
            else if(c=='}' && st.top()!='{'){
                return false;
            }
            st.pop();
            }
            else{
                return false;
            }
            
        }
        return st.empty();
    }
};