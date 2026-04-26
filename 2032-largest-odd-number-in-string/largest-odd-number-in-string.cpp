class Solution
{
public:
    string largestOddNumber(string &s)
    {
        string result = "";
        int n = s.size();
        int i = 0;
        int maxi = -1;
        int zeros = 0;
        while (i < n)
        {
            if ((s[i] - '0') % 2 != 0)
            {
                maxi = i;
            }
            i++;
        }

        if (maxi == -1)
            return "";

        i = 0;
        while (i < n && s[i] == '0')
        {
            zeros++;
            i++;
        }

        result = s.substr(zeros, maxi - zeros + 1);
        return result;
    }
};