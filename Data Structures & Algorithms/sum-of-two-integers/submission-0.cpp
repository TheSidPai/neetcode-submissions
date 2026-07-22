class Solution {
public:
    int getSum(int a, int b) {
        int res = 0, carry = 0;
        for(int i = 0; i < 32; i++){
            int one = (a >> i) & 1;
            int two = (b >> i) & 1;
            if(!one && !two){
                if(carry) res |= (1 << i);
                carry = 0;
            }
            else if(one && two){
                if(carry) res |= (1 << i);
                carry = 1;
            }
            else{
                if(!carry) res |= (1 << i);
                else carry = 1;
            }
        }

        return res;
    }
};
