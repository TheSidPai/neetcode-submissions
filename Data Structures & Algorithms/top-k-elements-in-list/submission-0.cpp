class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int num: nums) map[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>> heap;
        for(auto [a, b]: map) heap.push({b, a});

        vector<int> res;
        for(int i = 0; i < k; i++){
            auto [b, a] = heap.top();
            heap.pop();
            res.push_back(a);
        }

        return res;
    }
};
