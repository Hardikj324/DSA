class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int ans=INT_MIN;
        int h,l;
        while(i<j){
            h = min(height[i],height[j]);
            l=j-i;
            int area = l*h;
            ans = max(area,ans);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};