class Solution {
    vector<string> res;

public:
    vector<string> restoreIpAddresses(string s) {
        if (s.length() > 12) return res;
        backtrack(s, 0, 0, "");
        return res;
    }

private:
    void backtrack(string& s, int i, int dots, string curIP) {
        if (dots == 4 && i == s.size()) {
            res.push_back(curIP.substr(0, curIP.size() - 1));
            return;
        }
        if (dots > 4) return;

        for (int j = i; j < min(i + 3, (int)s.size()); j++) {
            if (i != j && s[i] == '0') continue;
            if (stoi(s.substr(i, j - i + 1)) < 256) {
                backtrack(s, j + 1, dots + 1, curIP + s.substr(i, j - i + 1) + ".");
            }
        }
    }
};