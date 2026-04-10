class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x / 2;
        long long mid;
        int ans = 0;
        if(x<2){return x;}
        while (left <= right)
        {
            mid = (left + right) / 2;
            cout << "This is the value of right " << right << endl;
            cout << "This is the value of mid " << mid << endl;
            cout << "This is the value of left " << left << endl;

            if (mid * mid <= x)
            {
                ans = mid; // This line is because if we got this line so we will have the previous rounded of answer of the x.
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