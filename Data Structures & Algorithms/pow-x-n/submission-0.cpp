class Solution {
public:
    double myPow(double x, int n) {
        if(n == 1) return x;
        if(n == 0) return 1;
        
        if(n < 0) return myPow((1/x), (-1)*n);

        if(n % 2) return x * myPow(x, n-1);
        else return myPow(x*x, n/2);
    }
};
