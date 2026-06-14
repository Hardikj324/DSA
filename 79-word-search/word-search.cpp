class Solution {
public:
    bool helper(vector<vector<char>>& board, string& word, int pos, int i, int j){
        if (pos == word.size()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='#') return false;
        if(board[i][j] != word[pos]) return false;

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = helper(board,word,pos+1,i+1,j) || helper(board,word,pos+1,i-1,j) || helper(board,word,pos+1,i,j+1) || helper(board,word,pos+1,i,j-1);

        board[i][j]=temp;
        
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n =board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(word[0]==board[i][j]){
                if(helper(board,word,0,i,j)) return true;
            }
        }
        }

        return false;
        
    }
};