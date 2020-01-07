class Solution {
public:
    double Power(double base, int exponent) {
        if (base == 0) return 0;
        if (exponent == 0) return 1;
        double result = 1.0;
        int iter_times = abs(exponent);
        for (int i = 0; i < iter_times; ++i){
            result *= base;
        }
        if (exponent < 0) result = 1.0 / result;
        return result;
    }
};