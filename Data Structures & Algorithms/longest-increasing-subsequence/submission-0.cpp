class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res = {};
        for(int i = 0; i < nums.size(); i++){
            auto a = lower_bound(res.begin(), res.end(), nums[i]);
            if(a == res.end()) res.push_back(nums[i]);
            else res[a - res.begin()] = nums[i];
        }

        return res.size();
    }
};
