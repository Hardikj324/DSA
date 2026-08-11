class Solution {
public:
    
    int minSwapsCouples(vector<int>& row) {
      int count = 0;
      int n = row.size();
      unordered_map<int,int> mp;
      for(int i=0;i<n;i++){
        mp[row[i]] = i;
      }
      for(int i=0;i<n;i=i+2){
        int first = row[i];
        int second = 0;
        if(first%2==0){
            second = first+1;
        }
        else{
            second = first-1;
        }
        if(row[i+1]!=second){
            count++;
            int partner = mp[second];
            swap(row[i+1],row[partner]);
            mp[row[partner]] = partner;
            mp[row[i+1]] = i+1;
        }
      }
      return count;
    }
};