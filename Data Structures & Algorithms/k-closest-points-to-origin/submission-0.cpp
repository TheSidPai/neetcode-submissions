class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>, vector<pair<double, int>>> heap;

        for(int i = 0; i < points.size(); i++){
            double x = points[i][0];
            double y = points[i][1];

            double len = sqrt((x*x) + (y*y));
            if(heap.size() < k) heap.push({len, i});
            else{
                double comp = heap.top().first;
                if(len < comp){
                    heap.pop();
                    heap.push({len, i});
                }
            }
        }

        vector<vector<int>> res;
        while(!heap.empty()){
            int idx = heap.top().second;
            res.push_back({points[idx][0], points[idx][1]});
            heap.pop();
        }

        return res;
    }
};
