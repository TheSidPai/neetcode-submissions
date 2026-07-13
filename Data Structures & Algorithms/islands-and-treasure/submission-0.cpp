class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> X = {0, -1, 0, 1};
        vector<int> Y = {-1, 0, 1, 0};

        vector<vector<int>> points;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) points.push_back({i, j});
            }
        }

        for(auto a: points){
            queue<tuple<int, int, int>> q;
            q.push({a[0], a[1], 0});

            while(!q.empty()){
                auto [x, y, dist] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++){
                    int nx = x + X[i];
                    int ny = y + Y[i];

                    if(nx >= 0 && ny >= 0 && nx < m && ny < n && dist+1 < grid[nx][ny]){
                        grid[nx][ny] = dist+1;
                        q.push({nx, ny, dist+1});
                    }
                }
            }
            
        }
    }
};
