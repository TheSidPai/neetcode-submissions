class Solution {
    int m, n;
    vector<int> X = {-1, 0, 1, 0};
    vector<int> Y = {0, -1, 0, 1};
public:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int x, int y){
        visited[x][y] = 1;
        for(int i = 0; i < 4; i++){
            int nx = x + X[i];
            int ny = y + Y[i];
            if(nx >= 0 && ny >= 0 && nx < m && ny < n && board[nx][ny] == 'O' && !visited[nx][ny]){
                visited[nx][ny] = 1;
                dfs(board, visited, nx, ny);
            } 
        }
    }
    void dfsb(vector<vector<char>>& board, vector<vector<int>>& visited, int x, int y){
        board[x][y] = 'X';
        for(int i = 0; i < 4; i++){
            int nx = x + X[i];
            int ny = y + Y[i];
            if(nx >= 0 && ny >= 0 && nx < m && ny < n && board[nx][ny] == 'O' && !visited[nx][ny]){
                visited[nx][ny] = 1;
                dfsb(board, visited, nx, ny);
            } 
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) cout<<board[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        vector<vector<int>> visited(m, vector<int> (n, 0));

        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O' && !visited[i][0]) dfs(board, visited, i, 0);
            if(board[i][n-1] == 'O' && !visited[i][n-1]) dfs(board, visited, i, n-1);
        }

        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O' && !visited[0][j]) dfs(board, visited, 0, j);
            if(board[m-1][j] == 'O' && !visited[m-1][j]) dfs(board, visited, m-1, j);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && board[i][j] == 'O'){
                    visited[i][j] = 1;
                    dfsb(board, visited, i, j);
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) cout<<board[i][j]<<" ";
            cout<<endl;
        }
    }
};
