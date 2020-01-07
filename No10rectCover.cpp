/*
* n = 1 f(n) = 1
* n = 2 f(n) = 2
* n >= 3 f(n) = f(n-1) + f(n-2)
*/
class Solution {
public:
    int rectCover(int number) {
        if (number == 0) return 0;
        if (number == 1) return 1;
        if (number == 2) return 2;
        int a = 1, b = 2, i = 3;
        int result = a + b;
        while (i++ < number)
        {
            a = b;
            b = result;
            result = a + b;
        }
        return result;
    }
};