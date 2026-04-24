class Solution
{
public:
    vector<string> printVertically(string s)
    {
        vector<string> words;
        string temp = "";

        for (auto letter : s)
        {
            if (letter == ' ')
            {
                words.push_back(temp);
                temp = "";
            }
            else
            {
                temp += letter;
            }
        }
        words.push_back(temp);

        int max_length = 0;
        for (auto word : words)
        {
            int len = word.size();
            max_length = max(max_length, len);
        }

        vector<string> ans;
        for (int i = 0; i < max_length; i++)
        {
            string row = "";

            for (int j = 0; j < words.size(); j++)
            {
                if (i < words[j].size())
                {
                    row += words[j][i];
                }
                else
                {
                    row += " ";
                }
            }
            while (!row.empty() && row.back() == ' ')
                row.pop_back();

            ans.push_back(row);
        }

        return ans;
    }
};