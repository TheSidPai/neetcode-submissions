class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0, maxf = 0;
        vector<int> map(26, 0);
        for(int i = 0; i<s.size(); i++){
            map[s[i] - 'A']++;
            maxf = max(maxf, map[s[i] - 'A']);
            if(right - left + 1 - maxf > k){
                map[s[left] - 'A']--;
                left++;
            }

            right++;
        }
        return right - left;
    }
};
