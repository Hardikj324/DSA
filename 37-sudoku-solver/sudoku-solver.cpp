class Solution {
public:
    int n = 0;
    int m = 0;

    bool is_valid(vector<vector<char>>& board,int x,int y){
        for(int i=0;i<n;i++){
            if(i==x){
                continue;
            }
            else{
                if(board[i][y]==board[x][y]){
                    return false;
                }
            }
        }

        for(int i=0;i<m;i++){
            if(i==y){
                continue;
            }
            else{
                if(board[x][i]==board[x][y]){
                    return false;
                }
            }
        }

        int col = y - y%3;
        int row = x - x%3;

        for(int i = row; i < row+3; i++){
            for(int j = col; j < col+3; j++){
                if(i == x && j == y){
                    continue;
                }
                else{
                    if(board[i][j] == board[x][y]){
                        return false;
                    }
                }
            }
        }

    return true;
    }

    bool solver(vector<vector<char>>& board){
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='.'){
                    for (char c = '1'; c <= '9'; c++){
                        board[i][j] = c;

                        if(is_valid(board,i,j)){
                            if(solver(board)){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                        else{
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }

            return true;
        }
    void solveSudoku(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        solver(board);
    }
};