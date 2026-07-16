class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int len = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            freq[s[i]]++;

            while(freq[s[i]] > 1){
                freq[s[left]]--;
                if(!freq[s[left]]) freq.erase(s[left]);
                left++;
            }

            len = max(len, i+1-left);
        }

        return len;
    }
};
