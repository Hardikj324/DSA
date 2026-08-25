class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        using P = pair<double, pair<int,int>>;
        priority_queue<P, vector<P>, greater<P>> pq;

        for(int i=0;i<n-1;i++){
            
            pq.push({(double)arr[i]/arr[n-1],{i,n-1}});
        }

        while(k--){
            auto current = pq.top();
            pq.pop();

            int i = current.second.first;
            int j = current.second.second;

            if(k==0){
                return {arr[i],arr[j]};
            }
            else if(j-1>i){
                pq.push({(double)arr[i]/arr[j-1],{i,j-1}});
            }
        }
        return {};
    }
};