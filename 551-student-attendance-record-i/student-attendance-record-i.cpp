class Solution {
public:
    bool checkRecord(string s) {
        int A=0;
        int cons_L=0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') {
                A++;
                if (A > 1) return false; 
                cons_L = 0; 
            } else if (s[i] == 'L') {
                cons_L++;
                if (cons_L > 2) return false; 
            } else {
                cons_L = 0; 
            }
        }
        return true;
        
    }
};