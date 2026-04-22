class Solution
{
public:
    bool Isvalid(string word, vector<string> &dictionary)
    {
        for (auto &d : dictionary)
        {
            int count = 0;

            for (int i = 0; i < word.size(); i++)
            {
                if (word[i] != d[i])
                {
                    count++;
                    if (count > 2)
                        break;
                }
            }

            if (count <= 2)
                return true;
        }

        return false;
    }

    vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary)
    {
        vector<string> ans;

        for (auto &q : queries)
        {
            if (Isvalid(q, dictionary))
                ans.push_back(q);
        }

        return ans;
    }
};