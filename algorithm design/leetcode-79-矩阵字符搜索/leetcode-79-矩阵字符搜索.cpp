class Solution {
private:
    bool dfs(vector<vector<char>>& board, string& word,int index, int x, int y){
        if(index >= word.size()) return true;
        char next = word[index];
        if(x>0 && board[x-1][y] == next){
            board[x-1][y] = ' ';
            bool ret = dfs(board,word, index +1, x-1, y);
            board[x-1][y] = next;
            if(ret) return true;
        } 
        if(y>0 && board[x][y-1] == next){
            board[x][y-1] = ' ';
            bool ret = dfs(board,word, index +1, x, y-1);
            board[x][y-1] = next;
            if(ret) return true;
        } 
        if(x<board.size() - 1 && board[x+1][y] == next){
            board[x+1][y] = ' ';
            bool ret = dfs(board,word, index +1, x+1, y);
            board[x+1][y] = next;
            if(ret) return true;
        } 
        if(y<board[x].size() - 1 && board[x][y+1] == next){
            board[x][y+1] = ' ';
            bool ret = dfs(board,word, index +1, x, y+1);
            board[x][y+1] = next;
            if(ret) return true;
        } 
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0) return true;
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j< board[i].size(); j++)
                if(board[i][j] == word[0]){
                    board[i][j] = ' ';
                    bool ret = dfs(board, word, 1, i,j);
                    board[i][j] = word[0];
                    if(ret) return true;
                }
        return false;
    }
};