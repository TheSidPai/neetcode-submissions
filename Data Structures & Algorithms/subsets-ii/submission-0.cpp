class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        track(res, curr, 0, nums);

        return res;
    }

    void track(vector<vector<int>>& res, vector<int>& curr, int idx, vector<int>& nums){
        if(idx >= nums.size()){
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        track(res, curr, idx+1, nums);
        curr.pop_back();

        int temp = nums[idx];
        while(idx < nums.size() && nums[idx] == temp) idx++;
        track(res, curr, idx, nums);
    }
};
