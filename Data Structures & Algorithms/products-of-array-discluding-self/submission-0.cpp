class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> back(n, 1);
        vector<int> front(n, 1);

        for(int i = 1; i < n; i++){
            int j = n-i-1;
            back[i] = nums[i-1] * back[i-1];
            front[j] = nums[j+1] * front[j+1];
        }

        for(int i = 0; i < n; i++){
            nums[i] = front[i] * back[i];
        }


        return nums;
    }
};
