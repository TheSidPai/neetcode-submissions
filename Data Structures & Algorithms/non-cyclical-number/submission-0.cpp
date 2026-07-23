class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> check;

        while(1){
            string a = to_string(n);
            int count = 0;
            cout<<a<<" ";
            for(char i: a) count += ((i - '0')*(i - '0'));

            if(count == 1) return true;
            if(check.count(count)) return false;
            
            check[count] = true;
            n = count;
        }
        return false;
    }
};
