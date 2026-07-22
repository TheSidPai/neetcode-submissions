class Solution {
public:
priority_queue<pair<int, int>, vector<pair<int, int>>> heap;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        for(int i = 0; i < k-1; i++) heap.push({nums[i], i});
        for(int i = k-1; i < nums.size(); i++){
            heap.push({nums[i], i});
            while(heap.top().second < i - (k-1)) heap.pop();
            res.push_back(heap.top().first);
        }

        return res;
    }
};
