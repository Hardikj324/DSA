class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> freq(256);
        for (int i = 0; i < 256; i++) {
            freq[i] = {0, (char)i};
        }

        for (char ch : s)
        {
            freq[(unsigned char)ch].first++;
        }
        sort(freq.begin(), freq.end(), [](auto &a, auto &b)
             { return a.first > b.first; });

        string result;
        for (auto &p : freq)
        {
           
            result.append(p.first,p.second);

        }
        return result;
    }
};