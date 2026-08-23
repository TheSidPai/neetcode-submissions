class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;

        comb(1, 0, n, k, curr);

        return res;
    }

    void comb(int idx, int size, int n, int k, vector<int>& curr){
        if(size == k){
            res.push_back(curr);
            return;
        }
        if(idx > n) return;

        curr.push_back(idx);
        comb(idx+1, size+1, n, k, curr);
        curr.pop_back();
        comb(idx+1, size, n, k, curr);
    }
};