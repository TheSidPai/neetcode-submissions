class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        int offset = 0;

        for(int i = 0; i <= n; i++){
            if(i == 0) res.push_back(0);
            else{
                if(i & (i-1)) res.push_back(1 + res[i - offset]);
                else{
                    res.push_back(1);
                    if(offset) offset *= 2;
                    else offset = 1;
                } 
            }
        }

        return res;
    }
};
