class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int X1 = max(rec1[0],rec2[0]);
        int Y1 = max(rec1[1],rec2[1]);
        int X2 = min(rec1[2],rec2[2]);
        int Y2 = min(rec1[3],rec2[3]);

        if(X1<X2 && Y1<Y2){
            return true;
        }


        return false;
    }
};