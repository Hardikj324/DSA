class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            int j = i;
            bool valid = false; 
            bool bad = false;   
            while (j > 0) {
                int digit = j % 10;
                if (digit == 3 || digit == 4 || digit == 7) {
                    bad = true;
                    break;
                }
                if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                    valid = true;
                }
                j /= 10;
            }
            if (!bad && valid) count++;
        }
        return count;
    }
};