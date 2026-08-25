class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
      int  l=0;
      int h =  letters.size() - 1;
      char ans = letters[0];
      while(l<=h){
        int mid = (l+h)/2;
        if(letters[mid]<=target){
            l = mid+1;
        }
        else{
            h = mid-1;
            ans = letters[mid];
        }
      }
    return ans;
    }
};