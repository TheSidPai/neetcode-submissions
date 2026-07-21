class Solution {
public:
vector<string> res;

    void dfs(string src, map<string, multiset<string>>& adj, vector<string>& res){
        while(!adj[src].empty()){
            string next = *adj[src].begin();
            adj[src].erase(adj[src].begin());
            dfs(next, adj, res);
        }
        res.push_back(src);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, multiset<string>> adj;
        for(auto& t: tickets) adj[t[0]].insert(t[1]);
        
        dfs("JFK", adj, res);

        reverse(res.begin(), res.end());

        return res;
    }
};
