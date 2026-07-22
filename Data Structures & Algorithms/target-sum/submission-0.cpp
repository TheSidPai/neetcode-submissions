class Solution {
public:
vector<vector<int>> dp;
int sum = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        sum = accumulate(nums.begin(), nums.end(), 0);
        dp = vector<vector<int>> (nums.size(), vector<int>((2*sum) + 1, INT_MIN));
        return backtrack(0, 0, nums, target);
    }

    int backtrack(int idx, int total, vector<int>& nums, int target){
        if(idx == nums.size()) return total == target;

        if (dp[idx][total + sum] != INT_MIN)  return dp[idx][total + sum];

        dp[idx][total+sum] = backtrack(idx+1, total-nums[idx], nums, target) + backtrack(idx+1, total+nums[idx], nums, target);

        return dp[idx][total+sum];
    }
};
