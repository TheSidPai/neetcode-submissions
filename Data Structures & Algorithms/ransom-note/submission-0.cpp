class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ran;
        unordered_map<char, int> mag;

        for(char c: ransomNote) ran[c]++;
        for(char c: magazine) mag[c]++;

        for(auto [a,b]: ran) if(b > mag[a]) return false;
        
        return true;
    }
};