class Solution {
    unordered_map<int, string> pad;
public:
    Solution() {
        pad[2] = "abc";
        pad[3] = "def";
        pad[4] = "ghi";
        pad[5] = "jkl";
        pad[6] = "mno";
        pad[7] = "pqrs";
        pad[8] = "tuv";
        pad[9] = "wxyz";
    }

    vector<string> letterCombinations(string digits) {
        string curr = "";
        vector<string> res;

        if(digits == "") return res;
        track(digits, 0, curr, res);

        return res;
    }

    void track(string digits, int idx, string curr, vector<string>& res){
        if(idx >= digits.size()){
            res.push_back(curr);
            return;
        }
        
        for(char c: pad[digits[idx] - '0']){
            curr.push_back(c);
            track(digits, idx+1, curr, res);
            curr.pop_back();
        }
    }
};
