class CountSquares {
    map<pair<int,int>, int> mp;
public:
    CountSquares() {}
    
    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int tally = 0;
        
        for(auto& [p, freq]: mp) {
            int x2 = p.first, y2 = p.second;
            
            // diagonal point must form a square
            if(x2 == x || abs(x2-x) != abs(y2-y)) continue;
            
            // other two corners
            tally += freq * mp[{x, y2}] * mp[{x2, y}];
        }
        
        return tally;
    }
};