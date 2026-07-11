class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;

        int low = *min_element(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());

        vector<int> curr;
        backtrack(nums, target, curr, res, low, 0);
        // vector<vector<int>> dp(target+1, {});
        // for(int i = low; i <= targetr; i++){
        //     for(int num: nums){
        //         if(i)
        //     }
        // }

        return res;
    }

    void backtrack(vector<int>& nums, int target, vector<int>& curr, vector<vector<int>>& res, int low, int idx){
        if(target == 0) res.push_back(curr);
        if(target < low) return;

        for(int i = idx; i < nums.size(); i++){
            int next = target - nums[i];
            if(next < low && next > 0) continue;
            curr.push_back(nums[i]);
            backtrack(nums, next, curr, res, low, i);
            curr.pop_back();
        }
    }
};
