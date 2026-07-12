class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        
        vector<int> parent(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;

        for(auto edge: edges){
            int a = edge[0];
            int b = edge[1];

            if(find(a, parent) != find(b, parent)) unionp(a, b, parent);
            else return false;
        }

        int p = find(0, parent);
        for(int i = 1; i < n; i++) if(find(i, parent) != p) return false;
        return true;
    }

    int find(int idx, vector<int>& parent){
        if(parent[idx] == idx) return idx;
        else return parent[idx] = find(parent[idx], parent);
    }

    void unionp(int a, int b, vector<int>& parent){
        parent[find(b, parent)] = find(a, parent);
    }
};
