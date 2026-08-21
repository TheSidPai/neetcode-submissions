class Solution {
public:
    string predictPartyVictory(string senate) {
        int cnt = 0, i = 0;

        while (i < senate.size()) {
            char c = senate[i];
            if (c == 'R') {
                if (cnt < 0) {
                    senate.push_back('D');
                }
                cnt++;
            } else {
                if (cnt > 0) {
                    senate.push_back('R');
                }
                cnt--;
            }
            i++;
        }

        return cnt > 0 ? "Radiant" : "Dire";
    }
};