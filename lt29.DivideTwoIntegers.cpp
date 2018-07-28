class Solution {
public:
    int divide(int dividend, int divisor) {       
        long long dvd = llabs(dividend);
        long long dvs = llabs(divisor);
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        
        long long res = 0;
        while (dvd >= dvs) {
            long long tmp = dvs;
            long long multiply = 1;
            while (dvd >= (tmp << 1)) {
                tmp <<= 1;
                multiply <<= 1;
            }
            res += multiply;
            dvd -= tmp;
        }
        
        res *= sign;
        if (res >= numeric_limits<int>::min() && res <= numeric_limits<int>::max())
            return res;
        
        return numeric_limits<int>::max(); 
    }
};
