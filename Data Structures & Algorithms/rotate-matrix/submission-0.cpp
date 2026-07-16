class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < (n/2); i++){
            for(int j = i; j < (n-i-1); j++){
                int prev = matrix[i][j];
                int r = i, c = j;
                for(int k = 0; k < 4; k++){
                    int temp = r;
                    r = c;
                    c = (n-(temp+1));

                    int back = matrix[r][c];
                    matrix[r][c] = prev;
                    prev = back;
                }
            }
        }
    }
};
