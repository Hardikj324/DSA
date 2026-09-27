class Solution {
public:
    int minTimeToType(string word) {
        int n = word.size();
        int total_count = 0;
        char lst = 'a' ;
        for(int i=0;i<n;i++){
            char curr = word[i];
            total_count += min(abs(lst-curr),26 - abs(lst-curr)) + 1;
            lst = curr;
        }
        return total_count;
    }
};