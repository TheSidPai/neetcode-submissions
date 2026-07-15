class Solution {
public:
int n;
vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> curr;
        vector<int> visited (n, 0);
        recurse(nums, visited, curr);

        return res;
    }
    void recurse(vector<int>& nums, vector<int>& visited, vector<int>& curr){
        if(curr.size() == n){
            res.push_back(curr);
            return;
        }

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                curr.push_back(nums[i]);
                visited[i] = 1;
                recurse(nums, visited, curr);

                visited[i] = 0;
                curr.pop_back();
            }
        }
    }
};
