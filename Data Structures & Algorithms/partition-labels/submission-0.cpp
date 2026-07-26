class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> main, curr;
        for(char a: s) main[a]++;
        vector<int> res;

        int prev = -1;
        for(int i = 0; i < s.size(); i++){
            curr[s[i]]++;
            if(curr[s[i]] == main[s[i]]) curr.erase(s[i]);

            if(curr.size() == 0){
                res.push_back(i - prev);
                prev = i;
            }
        }

        return res;
    }
};
