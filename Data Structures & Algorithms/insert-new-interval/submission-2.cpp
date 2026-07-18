class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0, n = intervals.size();
        vector<vector<int>> res;
        if(n == 0){
            res.push_back(newInterval);
            return res;
        }
        while(i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }
        if(i >= n){
            res.push_back(newInterval);
            return res;
        }
        if(intervals[i][0] > newInterval[1]){
            res.push_back(newInterval);
            while(i < n){
                res.push_back(intervals[i]);
                i++;
            }

            return res;
        }
        int start = min(intervals[i][0], newInterval[0]);
        int end = max(intervals[i][1], newInterval[1]);
        i++;
        while(i < n && intervals[i][0] <= end){
            end = max(end, intervals[i][1]);
            i++;
        }
        res.push_back({start, end});
        while(i < n) res.push_back(intervals[i++]);

        return res;
    }
};
