class Solution {
public:
    string result = "";
    char midChar = '$';
    int half = 0;

    bool solver(string& curr, vector<int>& count, string& target, int i, bool greater) {

        if(i==half){
            string candidate = curr; 
            string rightHalf = candidate;
            reverse(begin(rightHalf), end(rightHalf)); 
            
            if(midChar != '$')
                candidate += midChar; 

            candidate += rightHalf;

            if(candidate>target){
                result = candidate;
                return true;
            }

            return false;

        }

        for(char c = 'a'; c <= 'z'; c++){
            if (count[c - 'a'] == 0)
                continue;

            if(c<target[i] && !greater){
                continue;
            }

            curr.push_back(c);
            count[c - 'a']--;

            bool isgreater = greater||c>target[i];

            if(solver(curr,count,target,i+1,isgreater)){
                return true;
            }

            curr.pop_back();
            count[c - 'a']++;

        }

        return false;

    }

    string lexPalindromicPermutation(string s, string target) {
        vector<int> count(26,0);
        int n = s.size();
        int count_odd = 0;

        for(char c:s){
            count[c-'a']++;
        }

        for(int i=0;i<26;i++){
            if(count[i]%2==1){
                count_odd++;
                midChar = 'a' + i;
            }
        }

        if(count_odd>1){
            return "";
        }

        vector<int> halfCount(26, 0);
        for (int c = 0; c < 26; c++) {
            halfCount[c] = count[c] / 2;
        }

        half = n/2;
        string curr;

        solver(curr,halfCount,target,0,false);

        return result;
    }
};