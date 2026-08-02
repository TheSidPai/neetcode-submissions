class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(candidates, res, curr, target, 0, 0);

        return res;
    }

    void backtrack(vector<int>& candidates, vector<vector<int>>& res, vector<int> curr, int target, int idx, int sum){
        // cout<<"idx: "<<idx<<", sum: "<<sum<<endl;
        if(target == sum){
            res.push_back(curr);

            return;
        }
        if(idx >= candidates.size() || target < sum) return;
        
        curr.push_back(candidates[idx]);
        backtrack(candidates, res, curr, target, idx+1, sum+candidates[idx]);
        if(idx == candidates.size() - 1) return;
        curr.pop_back();
        int temp = candidates[idx];
        while(idx < candidates.size() && candidates[idx] == temp) idx++;
        backtrack(candidates, res, curr, target, idx, sum);
        
    }
};
