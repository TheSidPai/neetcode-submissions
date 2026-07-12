class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = 0;
        int maxneg = INT_MIN;
        int currSum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= 0) maxneg = max(maxneg, nums[i]);
            currSum += nums[i];
            if(currSum < 0) currSum = 0;
            
            res = max(res, currSum);
        }

        return res == 0 ? maxneg : res;
    }
};
