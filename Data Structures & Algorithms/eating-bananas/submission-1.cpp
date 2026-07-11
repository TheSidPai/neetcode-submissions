class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int res = high;
        while(low <= high){
            int mid = (low+high) / 2;
            int count = 0;
            for(int num: piles) count += ceil((double)num / mid);

            if(count <= h){
                res = min(mid, res);
                high = mid-1;
            }
            else low = mid+1;
        }

        return res;
    }
};
