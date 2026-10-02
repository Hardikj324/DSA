class Solution {
public:
    void solver(int n,vector<string> &vec,string s,int open,int close){
        if(s.size()==2*n){
            if(open==close){
                vec.push_back(s);
            }
            return ;
        }
        if(close>open){
            return ;
        }

        s.push_back('(');
        solver(n,vec,s,open+1,close);
        s.pop_back();

        s.push_back(')');
        solver(n,vec,s,open,close+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        solver(n,vec,"",0,0);
        return vec;
    }
};