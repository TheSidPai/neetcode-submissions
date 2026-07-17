class Solution {
public:
vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        string zero;
        vector<string> soln;
        for(int i = 0; i < n; i++) zero += '.';
        for(int i = 0; i < n; i++) soln.push_back(zero);

        traverse(0, n, soln);

        return res;
    }

    void traverse(int idx, int n, vector<string> soln){
        if(idx >= n){
            res.push_back(soln);
            return;
        }

        for(int i = 0; i < n; i++){
            if(isSafe(soln, i, idx, n)){
                soln[i][idx] = 'Q';
                traverse(idx+1, n, soln);
                soln[i][idx] = '.';
            }
        }
    }

    bool isSafe(vector<string> soln, int row, int col, int n){
        if(!(row >= 0 && col >= 0 && row < n && col < n)) return false;

        for(int j = 0; j < col; j++) if(soln[row][j] == 'Q') return false;

        for(int i = 1; i < n; i++){
            if(row-i >= 0 && col-i >= 0 && soln[row-i][col-i] == 'Q') return false;
        } 

        for(int i = 1; i < n; i++){
            if(row+i < n && col-i >= 0 && soln[row+i][col-i] == 'Q') return false;
        } 

        return true;
    }
};
