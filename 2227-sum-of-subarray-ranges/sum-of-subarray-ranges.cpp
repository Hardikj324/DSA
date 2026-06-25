class Solution {
public:
     vector<int> findNSE(vector<int> &arr) {
        
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n,n);

        for(int i=n-1;i>=0;i--){
            int currele = arr[i];

            while(!st.empty() && currele<=arr[st.top()]){
                st.pop();
            }

            if(!st.empty()){
              nse[i] = st.top();  
            }

            st.push(i);
        }
        
        return nse;
    }
    

    vector<int> findPSEE(vector<int> &arr) {
       int n = arr.size();
        stack<int> st;
        vector<int> psee(n,-1);


        for(int i=0;i<n;i++){
            int currele = arr[i];

            while(!st.empty() && currele<arr[st.top()]){
                st.pop();
            }

            if(!st.empty()){
              psee[i] = st.top();  
            }
            st.push(i);
        }
        
        return psee;
    }
    
    vector<int> findPGEE(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> pgee(n,-1);


        for(int i=0;i<n;i++){
            int currele = arr[i];

            while(!st.empty() && currele>arr[st.top()]){
                st.pop();
            }

            if(!st.empty()){
              pgee[i] = st.top();  
            }
            st.push(i);
        }
        
        return pgee;
        
    }

    vector<int> findNGE(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ngee(n,n);


        for(int i=n-1;i>=0;i--){
            int currele = arr[i];

            while(!st.empty() && currele>=arr[st.top()]){
                st.pop();
            }

            if(!st.empty()){
              ngee[i] = st.top();  
            }
            st.push(i);
        }
        
        return ngee;
        
    }
    long long sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();

        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);
        long long sum = 0;
        
        // Traverse on the array
        for(int i=0; i < n; i++) {
            
            int left = i - psee[i];
            
            int right = nse[i] - i;
            

            long long freq = left*right*1LL;
            
            long long val = (freq*arr[i]*1LL);
            
            sum += val;
        }
        
        return sum;
    }

    long long sumSubarrayMaxs(vector<int> &arr) {
        
        vector<int> nge = findNGE(arr);
        
        vector<int> pgee = findPGEE(arr);
        
        // Size of array
        int n = arr.size();
        
        long long sum = 0;
        
        for(int i=0; i < n; i++) {
            
            int left = i - pgee[i];
            
            int right = nge[i] - i;
            
            long long freq = left*right*1LL;
            
            long long val = (freq*arr[i]*1LL);
            
            sum += val;
        }
        
        return sum;
    }
    long long subArrayRanges(vector<int>& arr) {
       return ( sumSubarrayMaxs(arr) - 
                 sumSubarrayMins(arr) );

    }
};