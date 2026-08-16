class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);
        vector<int> visited(numCourses, 0);

        for(auto a: prerequisites){
            adj[a[1]].push_back(a[0]);
            indeg[a[0]]++;
        }

        queue<int> q;
        vector<int> res;
        for(int i = 0; i < numCourses; i++){
            if(!indeg[i]){
                q.push(i);
                visited[i] = 1;
            }
        }

        while(!q.empty()){
            int idx = q.front();
            q.pop();
            res.push_back(idx);

            for(int i: adj[idx]){
                indeg[i]--;
                if(!indeg[i] && !visited[i]){
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }

        if(res.size() == numCourses) return res;
        else return {};
    }
};
