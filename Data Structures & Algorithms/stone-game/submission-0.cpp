class Solution {
private:
    map<pair<int, int>, int> game;
public:
    bool stoneGame(vector<int>& piles) {
        if(solve(piles, 0, piles.size()-1) > 0) return true;
        else return false;
    }

    int solve(vector<int>& piles, int l, int r){
        if(game.count({l, r})) return game[{l, r}];
        else{
            if(l == r){
                game[{l, r}]=  piles[l];
                return game[{l, r}];
            }
            game[{l, r}] = max(piles[l] - solve(piles, l+1, r), piles[r] - solve(piles, l, r-1));
            return game[{l, r}];
        }
    }
};