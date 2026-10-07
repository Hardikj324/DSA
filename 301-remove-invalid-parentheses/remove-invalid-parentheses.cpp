class Solution {
public:
    set<string> st;
    int mini = INT_MAX;
    void solver(string &s,string &temp,set<string> &st,int i,int rem,int count){
        if(rem>mini) return ;
        if(i==s.size()){
            if(count==0){
            if(mini==rem){
                st.insert(temp);
            }
            else if(mini>rem){
                mini=rem;
                st.clear();
                st.insert(temp);
            }
            }
            return ;
        }

        if(count<0){
            return ;
        }

        if(isalpha(s[i])){
            temp.push_back(s[i]);
            solver(s,temp,st,i+1,rem,count);
            temp.pop_back();
        }
        else{
            temp.push_back(s[i]);
            if(s[i]=='(')
                solver(s,temp,st,i+1,rem,count+1);
            if(s[i]==')')
                solver(s,temp,st,i+1,rem,count-1);
            temp.pop_back();
            solver(s,temp,st,i+1,rem+1,count);
        }
    }
    vector<string> removeInvalidParentheses(string s) {

        
        string temp;
        solver(s,temp,st,0,0,0);
        vector<string> vec;

        for(auto se:st){
            vec.push_back(se);
        }
        return vec;
    }
};