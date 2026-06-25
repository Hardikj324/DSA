class Solution {
public:
    string removeKdigits(string num, int k) {
        string st = ""; // use string as stack
        
        for(char c : num) {
            while(!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }
        
        // remove remaining k digits from the end
        while(k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }
        
        // remove leading zeros
        int i = 0;
        while(i < st.size() && st[i] == '0') i++;
        
        string ans = st.substr(i);
        return ans.empty() ? "0" : ans;
    }
};
