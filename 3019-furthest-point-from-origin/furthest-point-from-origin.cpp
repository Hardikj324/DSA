class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans =0;
        int no_of_toatl = 0;
        char most_occurring = ' ';
        int dash_count = 0;
        int n= moves.size();
        for(int i=0;i<n;i++){
            if(moves[i]=='R'){
                no_of_toatl++;
            }
            else if(moves[i]=='L'){
                no_of_toatl--;
            }
            else{
                dash_count++;
            }
        }
        most_occurring  = (no_of_toatl>=0) ?'R':'L';
        return dash_count + abs(no_of_toatl);
    }
};