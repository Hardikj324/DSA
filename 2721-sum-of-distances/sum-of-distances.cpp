class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
    typedef long long ll;
    int n = nums.size();
    vector<ll> arr(n,0);
    unordered_map<int,ll> count;
    unordered_map<int,ll> sum;

    //Left
    for(int i=0;i<n;i++){
        ll freq = count[nums[i]];
        ll su =  sum[nums[i]];
        arr[i] += i*freq - su;
        count[nums[i]] +=1;
        sum[nums[i]] +=i;
    }

    count.clear();
    sum.clear();

    //Right
    for(int i=n-1;i>=0;i--){
        ll freq = count[nums[i]];
        ll su = sum[nums[i]];
        arr[i] += su-i*freq;
        count[nums[i]] +=1;
        sum[nums[i]] +=i;
    }
    return arr;

    }
};