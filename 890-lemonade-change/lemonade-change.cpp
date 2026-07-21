class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int r_5 = 0;
        int r_10 = 0;
        int n = bills.size();

        for(auto b:bills){
            if(b==5){
                r_5++;
            }
            else if (b == 10) {
                if (r_5 == 0) return false;
                r_5--;
                r_10++;
            }
            else{
                if(r_5>0 & r_10>0){
                    r_5--;
                    r_10--;
                }
                else if(r_5>=3){
                    r_5 = r_5-3;
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }
};