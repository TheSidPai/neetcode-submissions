class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int i: nums) freq[i]++;

        for(auto [a, b]: freq) if(b > n/2) return a;

        return 0;
    }
};