class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);
        for(char &c:tasks){
            mp[c-'A']++;
        }

        int time = 0;
        priority_queue<int> pq;

        for(int i=0;i<26;i++){
            if(mp[i]){
                pq.push(mp[i]);
            }
        }

        while(!pq.empty()){
            vector<int> temp;
            
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                int frq = pq.top();
                pq.pop();
                frq--;
                temp.push_back(frq);
                }
            }
            for(int &f:temp){
                if(f>0){
                    pq.push(f);
                }
            }

            if(pq.empty()){
                time += temp.size();
            }
            else{
                time +=n+1;
            }
        }
        return time;
    }
};