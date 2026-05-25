class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        stack<int> st;
        unordered_map <int,int> mp;
        vector<int> ans;

        st.push(nums2[0]);

        for(int i=1;i<m;i++){

            while(!st.empty() && nums2[i]>st.top()){
                    mp[st.top()] = nums2[i];
                    st.pop();
            }
                st.push(nums2[i]);
        }

        while(!st.empty()){
            mp[st.top()]=-1;
            st.pop();
        }
        for(int i=0;i<n;i++){
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};