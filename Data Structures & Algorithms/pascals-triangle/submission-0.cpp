class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> one;
        one.push_back(1);
        res.push_back(one);

        for(int i = 1; i < numRows; i++){
            vector<int> prev = res[i-1];
            vector<int> curr;
            for(int j = 0; j <= prev.size(); j++){
                int a, b;
                if(!j) a = 0;
                else a = prev[j-1];
                if(j == prev.size()) b = 0;
                else b = prev[j];

                int num = a + b;
                curr.push_back(num);
            }
            res.push_back(curr);
        }

        return res;
    }
};