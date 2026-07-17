class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        int row = 0;
        int col = 0;
        for(int i = 0; i < m; i++) if(arr[i][0] == 0){
            col = 1;
            break;
        } 
        for(int j = 0; j < n; j++) if(arr[0][j] == 0){
            row = 1;
            break;
        } 

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(arr[i][j] == 0){
                    arr[i][0] = 0;
                    arr[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < m; i++){
            if(arr[i][0] == 0){
                for(int j = 1; j < n; j++) arr[i][j] = 0;
            }
        }

        for(int j = 1; j < n; j++){
            if(arr[0][j] == 0){
                for(int i = 1; i < m; i++) arr[i][j] = 0;
            }
        }

        if(col) for(int i = 0; i < m; i++) arr[i][0] = 0;
        if(row) for(int j = 0; j < n; j++) arr[0][j] = 0;

    }
};
