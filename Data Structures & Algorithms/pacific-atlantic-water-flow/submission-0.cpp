class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        vector<int> X = {-1, 0, 1, 0};
        vector<int> Y = {0, -1, 0, 1};

        vector<vector<int>> visited(r, vector<int> (c, 0));
        vector<vector<int>> visiteds(r, vector<int> (c, 0));
        vector<vector<int>> res;

        queue<pair<int, int>> q;
        for(int i = 0; i < r; i++){
            q.push({i, 0});
            visited[i][0] = 1;
        }
        for(int j = 1; j < c; j++){
            q.push({0, j});
            visited[0][j] = 1;
        }
            

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nx = x + X[i];
                int ny = y + Y[i];

                if(nx >= 0 && ny >= 0 && nx < r && ny < c && !visited[nx][ny] && heights[nx][ny] >= heights[x][y]){
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        
        for(int i = 0; i < r; i++){
            q.push({i, c-1});
            visiteds[i][c-1] = 1;
        }
        for(int j = 0; j < c-1; j++){
            q.push({r-1, j});
            visiteds[r-1][j] = 1;
        }
            

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nx = x + X[i];
                int ny = y + Y[i];

                if(nx >= 0 && ny >= 0 && nx < r && ny < c && !visiteds[nx][ny] && heights[nx][ny] >= heights[x][y]){
                    visiteds[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        // for(int i = 0; i < r; i++){
        //     for(int j = 0; j < c; j++) cout<<visited[i][j]<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;
        // for(int i = 0; i < r; i++){
        //     for(int j = 0; j < c; j++) cout<<visiteds[i][j]<<" ";
        //     cout<<endl;
        // }
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(visited[i][j] && visiteds[i][j]) res.push_back({i, j});
            }
        }

        return res;
    }
};
