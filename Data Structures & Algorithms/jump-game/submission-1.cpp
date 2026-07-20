class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int range = 0;
        
        for(int i = 0; i < n; i++) if(nums[i] && i <= range) range = min(n-1, max(i+nums[i], range));

        return range >= n-1;
    }
};
