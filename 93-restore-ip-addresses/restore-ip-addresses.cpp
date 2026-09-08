class Solution {
public:
    bool is_valid(string s){
        if(s.size() > 3) return false;
        if(s.size() > 1 && s[0] == '0') return false;
        int val = stoi(s);
        if(val < 0 || val > 255) return false;
        return true;
    }
    void solver(vector<string> &vec,string s,int idx,int part,string curr){
        if(part == 4 && idx == s.size()){
            vec.push_back(curr);
            return;
        }

        if(part == 4 || idx == s.size()) return;

        for(int len=1;len<=3 && (len + idx)<=s.size();len++){
            string seg = s.substr(idx, len);
            if(is_valid(seg)){
                string next = (part==0 ?seg:curr + "." + seg);
                solver(vec,s,idx+len,part+1,next);
            }
        }
        

    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        solver(res, s, 0, 0, "");
        return res;
    }
};