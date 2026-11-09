class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> vec;
        int n = s1.size();
        int i=0;
        while(i<n){

         if(s1[i]!=s2[i]){
            vector<string> temp(2,"");
            while(i<n && s1[i]!=s2[i]){
                temp[0].push_back(s1[i]);
                temp[1].push_back(s2[i]);
                i++;
            }
            vec.push_back(temp);
         }
        else{
            i++;
        }
        }
        return vec;
    }
};