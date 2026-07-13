class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while(left <= right){
            char l = check(s[left]);
            char r = check(s[right]);
            if(l == '*') left++;
            else if(r == '*') right--;
            else{
                if(l != r) return false;
                left++;
                right--;
            }
        }

        return true;
    }

    char check(char c){
        if(c >= 'a' && c <= 'z') return c;
        else if(c >= 'A' && c <= 'Z') return 'a' + (c - 'A');
        else if(c >= '0' && c <= '9') return c;
        else return '*';
    }
};
