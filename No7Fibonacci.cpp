class Solution {
public:
    int Fibonacci(int n) {
        int a = 0,b = 1,tmp;
        if (n ==0 ) return 0;
        if (n == 1) return 1;
        for (int i = 2; i <= n; ++i){
            tmp = a + b;
            a = b;
            b = tmp;
        }
        return b;
    }
};