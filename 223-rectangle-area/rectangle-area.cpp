class Solution {
public:
    
    int area_of_rectangle(int x1, int y1, int x2, int y2){
        return abs(x2 - x1) * abs(y2 - y1);
    }

    int computeArea(int ax1, int ay1, int ax2, int ay2,
                    int bx1, int by1, int bx2, int by2) {
        
        int areaA = area_of_rectangle(ax1, ay1, ax2, ay2);
        int areaB = area_of_rectangle(bx1, by1, bx2, by2);

        int overlapX1 = max(ax1,bx1);
        int overlapY1 = max(ay1,by1);
        int overlapX2 = min(ax2,bx2);
        int overlapY2 = min(ay2,by2);

        int overlapArea = 0;
        if (overlapX1 < overlapX2 && overlapY1 < overlapY2) {
            overlapArea = area_of_rectangle(overlapX1, overlapY1, overlapX2, overlapY2);
        } 

        return areaA + areaB - overlapArea;
                    }
};