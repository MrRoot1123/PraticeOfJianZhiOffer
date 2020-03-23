#include <string>

using namespace std;

/*
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
*/

class Solution {
public:
    int StrToInt(string str) {
        int flag = 1;
        int res = 0;
        for (int i = 0; i < str.size(); ++i)
        {
            if (i == 0 && str[i] == '+')
                continue;
            else if (i == 0 && str[i] == '-')
                flag = -1;
            else
            {
                if (str[i] - '0' <= 9 && str[i] - '0' >= 0)
                {
                    res *= 10;
                    res += (str[i] - '0');
                }
                else
                {
                    res = 0;
                    break;
                }
            }
        }
        res *= flag;
        if ((flag == -1 && res > 0) || (flag == 1 && res < 0))  // 防止溢出
            res = 0;
        return res;
    }
};

int main()
{
    string test1 = "-2147483649";
    Solution s = Solution();
    s.StrToInt(test1);
    return 0;
}