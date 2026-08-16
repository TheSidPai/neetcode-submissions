class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> orig;
        for (char c : t) orig[c]++;
        int required = orig.size();

        unordered_map<char,int> freq;
        int matched = 0;
        int best = INT_MAX, bestLeft = -1;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            if (orig.count(c)) {
                freq[c]++;
                if (freq[c] == orig[c]) matched++;
            }

            while (matched == required) {
                if (right - left + 1 < best) {
                    best = right - left + 1;
                    bestLeft = left;
                }
                char lc = s[left];
                if (orig.count(lc)) {
                    freq[lc]--;
                    if (freq[lc] == orig[lc] - 1) matched--;
                }
                left++;
            }
        }

        return best == INT_MAX ? "" : s.substr(bestLeft, best);
    }
};
