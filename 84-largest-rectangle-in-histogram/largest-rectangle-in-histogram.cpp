class Solution {
public:
    vector<int> findPSE(vector<int> &heights) {
    int n = heights.size();
    vector<int> pse(n, -1);   // default: -1 if none
    stack<int> st;            // store indices

    for(int i = 0; i < n; i++) {
        while(!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if(!st.empty()) {
            pse[i] = st.top();
        }
        st.push(i);
    }
    return pse;
}

    vector<int> findNSE(vector<int> &heights) {
    int n = heights.size();
    vector<int> nse(n, n);    // default: n if none
    stack<int> st;            // store indices

    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if(!st.empty()) {
            nse[i] = st.top();
        }
        st.push(i);
    }
    return nse;
}


    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);
        int maxi = INT_MIN;
        int n = heights.size();
        for(int i=0;i<n;i++){
            maxi = max(maxi,heights[i]*(nse[i]-pse[i]-1));
        }
        return maxi;
    }
};