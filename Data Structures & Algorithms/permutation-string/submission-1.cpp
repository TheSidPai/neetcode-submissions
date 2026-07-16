class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> check(26, 0);
        vector<int> comp(26, 0);
        for(char c: s1) check[c - 'a']++;

        int n = s2.size();
        int len = s1.size();
        for(int i = 0; i < len-1; i++){
            comp[s2[i] - 'a']++;
        }
        int left = -1;
        for(int i = len-1; i < n; i++){
            if(left >= 0) comp[s2[left] - 'a']--;
            left++;
            comp[s2[i] - 'a']++;
            int flag = 1;
            for(int j = 0; j < 26; j++) if(flag && comp[j] != check[j]) flag = 0;

            if(flag) return true;
        }

        return false;
    }
};
