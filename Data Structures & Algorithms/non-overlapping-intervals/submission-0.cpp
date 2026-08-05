class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int cs = intervals[0][0], ce = intervals[0][1];
        int count = 0;
        for(int i = 1; i < intervals.size(); i++){
            int s = intervals[i][0], e = intervals[i][1];
            if(s >= ce){
                cs = s;
                ce = e;
            }
            else{
                count++;
                if(e < ce){
                    cs = s;
                    ce = e;
                }
            }
        }

        return count;
    }
};
