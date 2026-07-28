class Solution {
public:
    
    bool checkValidString(string str) {
        int minOpen = 0;
        int maxOpen = 0;

        for(char s:str){
            if(s=='('){
                minOpen++;
                maxOpen++;
            }
            else if(s==')'){
                minOpen--;
                maxOpen--;
            }
            else{
                minOpen--;
                maxOpen++;
            }
            if(maxOpen<0){
                return false;
            }
            minOpen = max(minOpen, 0);
        }
        return minOpen == 0;
    }
};