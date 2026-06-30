class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int count = 0;

        unordered_map<char,int> mp;
        mp['a']=0;
        mp['b']=0;
        mp['c']=0;

   

        while(right<n){
            mp[s[right]]++;
            right++;
            while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1){
            count += n-right+1; 
            
            mp[s[left]]--;
            left++;
            }
        }
        

        return count;
    }
};