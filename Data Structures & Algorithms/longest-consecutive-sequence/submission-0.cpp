class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> mp;
        for(int num: nums) mp[num] = 1;
        for(int num: nums){
            if(!mp.count(num-1)){
                int count = 1;
                int i = num+1;
                while(mp.count(i)){
                    count++;
                    i++;
                }
                res = max(res, count);
            }
        }

        return res;
    }
};
