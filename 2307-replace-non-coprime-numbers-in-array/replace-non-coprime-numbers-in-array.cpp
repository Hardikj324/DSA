class Solution {
public:
    bool non_coprime(int a,int b){
        return gcd(a,b) > 1;
    }
    long long LCM(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();

        for(int i=0;i<n;i++){
            int num = nums[i];
            while(!st.empty() && non_coprime(st.top(),num)){
                int lcm = LCM(st.top(),num);
                num = lcm;
                st.pop();
            }
                st.push(num);
            
        }

        vector<int> ans;
        n = st.size();
        for(int i=0;i<n;i++){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};