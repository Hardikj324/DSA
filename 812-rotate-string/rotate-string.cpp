class Solution {
public:
    bool rotateString(string s, string goal) {
            string rotated = s + s;
        int n = s.size();
        int m = goal.size();
        if (n != m)
            return false;

        if (rotated.find(goal) != string::npos)
        {
            return true;
        }
        return false;
    }
};