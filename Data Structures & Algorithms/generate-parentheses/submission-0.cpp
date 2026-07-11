class Solution {
public:
vector<string> res;
    vector<string> generateParenthesis(int n) {
        string emp = "";
        backtrack(emp, 0, 0, 0, 2*n);

        return res;
    } 

    void backtrack(string curr, int open, int close, int count, int lim){
        if(close > open) return;
        if(count == lim) res.push_back(curr);

        if(open < lim/2) backtrack(curr+"(", open+1, close, count+1, lim);
        if(open > close) backtrack(curr+")", open, close+1, count+1, lim);
    }
};
