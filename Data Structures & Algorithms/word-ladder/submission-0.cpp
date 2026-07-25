class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adj;
        for(string& word: wordList){
            for(int i = 0; i < word.size(); i++){
                string pattern = word;
                pattern[i] = '*';
                adj[pattern].push_back(word);
            }
        }

        unordered_map<string, bool> visited;

        queue<pair<string, int>> q;
        q.push({beginWord, 0});
        visited[beginWord] = true;

        while(!q.empty()){
            auto [word, step] = q.front();
            q.pop();

            for(int i = 0; i < word.size(); i++){
                string temp = word;
                temp[i] = '*';
                for(auto a: adj[temp]){
                    if(a == endWord) return step+2;
                    if(visited.count(a)) continue;

                    q.push({a, step+1});
                    visited[a] = true;
                }

            }
        }

        return 0;
    }
};
