
/*
f(n) = f(n-1) + f(f-2) + ... + f(1)
f(n-1) = f(n-1) + f(n-3) + ... + f(1)
所以f(n) = 2f(n-1)
f(n) = 2^(n-1)
*/

class Solution {
public:
    int jumpFloorII(int number) {
        return (1<<(number-1));
    }
};

