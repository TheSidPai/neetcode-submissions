class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int> (n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                res = max(res, dfs(i, j, memo, matrix));
            }
        }

        return res;
    }

    int dfs(int i, int j, vector<vector<int>>& memo, const vector<vector<int>>& matrix) {
        if (memo[i][j] != 0) {
            return memo[i][j];
        }

        int res = 1;
        int rows = matrix.size();
        int cols = matrix[0].size();

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (auto& dir : dirs) {
            int nx = i + dir[0];
            int ny = j + dir[1];

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                if (matrix[nx][ny] > matrix[i][j]) {
                    res = max(res, 1 + dfs(nx, ny, memo, matrix));
                }
            }
        }

        memo[i][j] = res;
        return res;
    }
};
