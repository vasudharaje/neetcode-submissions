class Solution {

private:
int rows, cols;
    bool dfs(vector<vector<char>>& board,string word,int r, int c, int i){
        if(i == word.size()){
            return true;
        }
        if(r >= rows || c >= cols || r<0 || c<0 || word[i] != board[r][c] || board[r][c] == '#' ){
            return false;
        }
        board[r][c] = '#';
        bool try1 = dfs(board, word, r+1, c, i+1);
        bool try2 = dfs(board, word, r-1, c, i+1);
        bool try3 = dfs(board, word, r, c+1, i+1);
        bool try4 = dfs(board, word, r, c-1, i+1);
        board[r][c] = word[i];
        return (try1 || try2 || try3 || try4);
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
