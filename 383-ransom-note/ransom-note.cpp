class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq1(26,0);
        for(int i=0;i<ransomNote.size();i++){
            char c = ransomNote[i];
            freq1[c-'a']++;
        }

        for(int i=0;i<magazine.size();i++){
            char c = magazine[i];
            if(freq1[c-'a']!=0){
                freq1[c-'a']--;
            }
        }

        for(int i=0;i<ransomNote.size();i++){
            char c = ransomNote[i];
            if(freq1[c-'a']!=0){
                return false;
            }
        }

        return true;

    }
};