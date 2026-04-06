class Solution {
public:
    bool judgeCircle(string moves) {
        int i=0;
        int v=0;
        int h=0;
        while(i<moves.size()){
            if(moves[i]=='L'){
                h--;
            }
            else if(moves[i]=='R'){
                h++;
            }
            else if(moves[i]=='U'){
                v++;
            }
            else if(moves[i]=='D'){
                v--;
            }
            i++;
        }
        if(h!=0 || v!=0){
            return false;
        }
        else{
            return true;
        }
    }
};