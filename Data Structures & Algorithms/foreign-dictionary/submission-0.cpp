class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<int> indeg(26, 0);
        unordered_map<int, bool> freq;
        for(int i = 0; i < words.size(); i++){
            for(char c: words[i]) freq[c-'a'] = true;
        }
        for(int i = 1; i < words.size(); i++){
            if(words[i].size() < words[i-1].size() && words[i-1].contains(words[i])) return "";
            for(int j = 0; j < min(words[i].size(), words[i-1].size()); j++){
                if(words[i][j] == words[i-1][j]) continue;
                adj[words[i-1][j] - 'a'].push_back(words[i][j] - 'a');
                indeg[words[i][j] - 'a']++;
                break;
            }
        }

        queue<int> q;
        string res;
        for(int i = 0; i < 26; i++) if(freq.count(i) && !indeg[i]) q.push(i);

        while(!q.empty()){
            int idx = q.front();
            q.pop();
            res += ('a' + idx);

            for(auto a: adj[idx]){
                indeg[a]--;
                if(indeg[a] == 0) q.push(a);
            }
        }

        for(int i = 0; i < 26; i++) if(indeg[i] > 0) return "";
        
        return res;
    }
};
