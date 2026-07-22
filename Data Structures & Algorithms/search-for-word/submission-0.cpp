class Solution {
public:

    int m, n;

    bool back(vector<vector<char>>& board, vector<vector<int>>& visited, int x, int y, string word, int idx){
        if(idx >= word.size()) return true;

        if(board[x][y] != word[idx]) return false;

        vector<int> X = {-1, 0, 1, 0};
        vector<int> Y = {0, -1, 0, 1};
        visited[x][y] = 1;
        if(idx == word.size()-1) return true;
        // cout<<"satisfied "<<x<<" "<<y<<" for "<<word[idx]<<endl;
        for(int i = 0; i < 4; i++){
            int nx = x + X[i];
            int ny = y + Y[i];

            if(nx >= 0 && ny >= 0 && ny < n && nx < m && !visited[nx][ny]){
                if(back(board, visited, nx, ny, word, idx+1)) return true;
            }
        }

        visited[x][y] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        vector<vector<int>> visited(m, vector<int> (n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(word[0] == board[i][j]){
                    // cout<<i<<" "<<j<<endl;
                    if(back(board, visited, i, j, word, 0)) return true;
                }
            }
        }

        return false;
    }
};
