class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxLen = 1;
        
        auto expand = [&](int l, int r) {
            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
        };
        
        for(int i = 0; i < n; i++) {
            expand(i, i);     // odd length
            expand(i, i+1);   // even length
        }
        
        return s.substr(start, maxLen);
    }
};
