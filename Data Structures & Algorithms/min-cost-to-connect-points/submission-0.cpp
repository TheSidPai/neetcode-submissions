class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, int>> pts;
        for(auto p: points) pts.push_back({p[0], p[1]});

        vector<int> visited(n, 0);
        vector<int> minDist(n, INT_MAX);

        visited[0] = 1;
        minDist[0] = 0;
        int total = 0;
        int last = 0;

        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[j]) continue;

                minDist[j] = min(minDist[j], (abs(pts[last].first - pts[j].first) + abs(pts[last].second - pts[j].second)));
            }
            int curr = INT_MAX, next;
            for(int j = 0; j < n; j++){
                if(visited[j] || curr <= minDist[j]) continue;
                curr = minDist[j];
                next = j;
            }
            visited[next] = 1;
            total += minDist[next];
            last = next;
        }

        return total;
    }
};
