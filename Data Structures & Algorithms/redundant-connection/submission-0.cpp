class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent (edges.size());
        for(int i = 0; i < parent.size(); i++) parent[i] = i;

        for(auto c: edges){
            int a = c[0];
            int b = c[1];
            if(find(a-1, parent) != find(b-1, parent)) unionp(a-1, b-1, parent);
            else return {a,b};
        }

        for(int num: parent) cout<<num<<" ";
        return edges[0];
    }

    int find(int idx, vector<int>& parent){
        if(parent[idx] == idx) return idx;
        else return parent[idx] = find(parent[idx], parent);
    }

    void unionp(int a, int b, vector<int>& parent){
        parent[find(a, parent)] = find(b, parent);
    }
};
