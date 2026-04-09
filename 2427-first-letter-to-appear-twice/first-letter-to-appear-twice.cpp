class Solution {
public:
    char repeatedCharacter(string s) {
       vector<int> seen(26,0);
        for(auto a:s){
            seen[a -'a']++;
            if(seen[a -'a']==2){
                return a;
            }
        }
        return ' ';
    }
};