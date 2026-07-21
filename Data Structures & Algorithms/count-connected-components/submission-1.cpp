class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;

        for(auto edge: edges){
            unions(edge[0], edge[1], parent);
        }

        unordered_set<int> res;
        for(int i = 0; i < n; i++) res.insert(find(i, parent));
        return res.size();
    }

    int find(int x, vector<int>& parent){
        if(parent[x] == x) return x;
        else return parent[x] = find(parent[x], parent);
    }

    void unions(int x, int y, vector<int>& parent){
        int a = find(x, parent);
        int b = find(y, parent);

        if(a == b) return;

        parent[b] = a;
    }
};
