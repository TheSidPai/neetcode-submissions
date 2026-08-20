class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> f;
        int n = nums.size();
        
        for(int i: nums) f[i]++;

        vector<int> res;
        for(auto [a, b]: f) if(b > n/3) res.push_back(a);

        return res;
    }
};