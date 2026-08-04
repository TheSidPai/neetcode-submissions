class Solution {
int res = 0, m, n, curr;
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y){
        curr++;
        // res = max(res, curr);

        vector<int> X = {-1, 0, 1, 0};
        vector<int> Y = {0, -1, 0, 1};

        for(int i = 0; i < 4; i++){
            int nx = x + X[i];
            int ny = y + Y[i];

            if(nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny] && grid[nx][ny]){
                visited[nx][ny] = 1;
                dfs(grid, visited, nx, ny);
                // cout<<"dfs of "<<nx<<" "<<ny<<", "<<curr<<endl;

            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> visited(m, vector<int> (n, 0));

        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] && !visited[i][j]){
                    count++;
                    curr = 0;
                    visited[i][j] = 1;
                    dfs(grid, visited, i, j);
                    res = max(res, curr);
                    // cout<<"dfs of "<<i<<" "<<j<<", "<<curr<<endl;
                }
            }
        }

        return res;
    }
};
