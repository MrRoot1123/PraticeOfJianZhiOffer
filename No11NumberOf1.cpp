/*
* 巧用位运算
*/
class Solution {
public:
     int  NumberOf1(int n) {
         int cnt = 0, flag = 1;
         while (flag != 0){
             if (n & flag) ++cnt;
             flag = flag << 1;
         }
         return cnt;
     }
};