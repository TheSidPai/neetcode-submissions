class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;
        int res = INT_MAX;
        while(left <= right){
            int mid = (left+right)/2;
            res = min(res, nums[mid]);
            
            if(nums[mid] < nums[right]) right = mid-1;
            else left = mid+1;
        }

        return res;
    }
};
