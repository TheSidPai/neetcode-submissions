class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int good = accumulate(gas.begin(), gas.end(), 0);
        int bad = accumulate(cost.begin(), cost.end(), 0);
        if(good < bad) return -1;

        int start = 0, tank = 0;
        for(int i = 0; i < gas.size(); i++){
            tank += gas[i] - cost[i];
            if(tank < 0){
                start = i+1;
                tank = 0;
            }
        }
        return start;
    }
};
