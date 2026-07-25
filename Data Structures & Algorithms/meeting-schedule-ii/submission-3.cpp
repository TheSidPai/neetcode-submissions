/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> start;
        vector<int> end;
        for(auto a: intervals){
            start.push_back(a.start);
            end.push_back(a.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int s = 0, e = 0, curr = 0, res = 0;
        while(s < n && e < n){
            if(start[s] < end[e]){
                curr++;
                res = max(res, curr);
                s++;
            } else{
                e++;
                curr--;
            }
        }

        return res;
    }
};
