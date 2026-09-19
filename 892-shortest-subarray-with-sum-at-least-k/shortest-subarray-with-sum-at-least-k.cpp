class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> pre(n,0);
        int j =0;
        int mini = INT_MAX;
        while(j<n){
            if(j==0){
                pre[j] = nums[j];
            }
            else{
                pre[j] = pre[j-1] + nums[j];
            }

            if(pre[j]>=k){
                mini = min(mini,j+1); 
            }

            //Shrinking the window
            while(!q.empty() && (pre[j]-pre[q.front()])>=k){
                mini = min(mini,j - q.front()); 
                q.pop_front();
            }

            //Monotonic
            while(!q.empty() && pre[j]<=pre[q.back()]){
                q.pop_back();
            }
            q.push_back(j);
            j++;
        }
        
        if(mini==INT_MAX){
            return -1;
        }
        return mini;
    }
};