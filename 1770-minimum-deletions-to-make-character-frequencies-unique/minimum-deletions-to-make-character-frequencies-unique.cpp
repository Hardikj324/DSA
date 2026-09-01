class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        vector<int> freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }

        sort(freq.rbegin(),freq.rend());
        int max_freq = freq[0]; 
        int del = 0;
        for(int i=0;i<26;i++){
            int curr = freq[i];

            if(curr==0) break;
            if(max_freq<curr){
                del += curr - max_freq;
                freq[i] = max_freq;
                curr = freq[i];
            }

            max_freq = max(0,curr-1);
        }
        return del;
    }
};