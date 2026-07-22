class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for(int i = 0; i < 16; i++){
            int a = (n >> i) & 1;
            int b = (n >> (31-i)) & 1;
            
            n = n & ~(1 << i);
            n = n & ~(1 << (31-i));

            if(a) n |= (1 << (31-i));
            if(b) n |= (1 << i);
        }

        return n;
    }
};
