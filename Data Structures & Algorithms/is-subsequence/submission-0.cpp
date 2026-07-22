class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0, main = 0;
        if(s.size() == 0) return true;
        while(main < t.size()){
            if(s[idx] == t[main]){
                main++;
                idx++;
                if(idx == s.size()) return true;
            }
            else main++;
        }

        return false;
    }
};