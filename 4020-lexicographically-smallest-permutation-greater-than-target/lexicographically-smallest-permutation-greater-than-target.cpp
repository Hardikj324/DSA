class Solution {
public:
    string ans = "";
    bool solver(string &curr,string target,vector<int>&count,int i,bool greater){
            if(i==target.size()){
                if(greater){
                    ans = curr;
                    return true;
                }
                return false;
            }
            for(char ch = 'a';ch<='z';ch++){
                if(count[ch-'a']==0) continue;

                if(!greater && ch<target[i]){
                    continue;
                }

                curr.push_back(ch);
                count[ch-'a']--;

                bool isgreater = greater || ch>target[i];

                if(solver(curr,target,count,i+1,isgreater)){
                    return true;
                }
                curr.pop_back();
                count[ch-'a']++;

            }
            return false;
       
    }
    string lexGreaterPermutation(string s, string target) {
            vector<int> count(26,0);
            for(int i=0;i<s.size();i++){
                count[s[i]-'a']++;
            }
            string curr;
            solver(curr,target,count,0,false);
            return ans;
    }
};