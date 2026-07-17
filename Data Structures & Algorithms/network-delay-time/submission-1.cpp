class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj (n);
        for(auto pairs: times) adj[pairs[0]-1].push_back({pairs[1]-1, pairs[2]});

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
        vector<int> time(n, INT_MAX);
        time[k-1] = 0;
        heap.push({0, k-1});

        while(!heap.empty()){
            auto [t, node] = heap.top();
            heap.pop();

            for(auto a: adj[node]){
                if(time[a.first] > t + a.second){
                    time[a.first] = t + a.second;
                    heap.push({time[a.first], a.first});
                }
            }
        }

        for(int i = 0; i < n; i++) if(time[i] == INT_MAX) return -1;
        
        return *max_element(time.begin(), time.end());
    }
};
