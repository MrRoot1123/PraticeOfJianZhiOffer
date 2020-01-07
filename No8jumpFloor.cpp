class Solution {
public:
    int jumpFloor(int number) {
        if (number == 1) return 1;
        if (number == 2) return 2;
        return jumpFloor(number-1) + jumpFloor(number-2);
    }
};

/*
number = 1 return 1
number = 2 return 2
number > 2 return jumpFllor(number-1) + jumpFloor(number-2)
所以返回结果实际是斐波那契数列
*/

class Solution2 {
public:
    int jumpFloor(int number) {
        if (number == 1) return 1;
        if (number == 2) return 2;
        int a = 1, b = 2, n = 2, tmp;
        while (n++ < number){
            tmp = a + b;
            a = b;
            b = tmp;
        }
        return b;
    }
};