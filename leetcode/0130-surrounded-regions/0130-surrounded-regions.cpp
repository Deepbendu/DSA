class Solution {
public:
    int m;
    int n;
    void dfs(int i, int j,  vector<vector<int>> &visited, vector<vector<char>>& board){
        if(i<0 || j<0 || i>=m || j>=n){
            return;
        }

        if(visited[i][j] || board[i][j] != 'O'){
            return;
        }

        if(board[i][j] == 'O'){
            visited[i][j] = 1;
        }
        
        dfs(i+1, j, visited, board);
        dfs(i-1, j, visited, board);
        dfs(i, j-1, visited, board);
        dfs(i, j+1, visited, board);
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        vector<vector<int>> visited (m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            if(board[i][0]=='O' && !visited[i][0]){
                dfs(i, 0, visited, board);
            }
            if(board[i][n-1] =='O' && !visited[i][n-1]){
                dfs(i, n-1, visited, board);
            }
        }

        for(int j=0; j<n; j++){
            if(board[0][j]=='O' && !visited[0][j]){
                dfs(0, j, visited, board);
            }
            if(board[m-1][j] =='O' && !visited[m-1][j]){
                dfs(m-1, j, visited, board);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};