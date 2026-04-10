class Solution {
public:
    int mySqrt(int x) 
    {
        int ans;
        long long right = x,left = 0,mid;
        while(left <= right)
        {
            mid = (left + right)/2;
            if(mid * mid == x)
            {
                return mid;
            }
            else if((mid * mid) < x)
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }
};