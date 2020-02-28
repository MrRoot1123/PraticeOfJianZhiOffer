#include <iostream>

using namespace std;
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if (n <= 0)
            return 0;
        int count = 0;
        for (int i = 1; i <= n; i *= 10)
        {
            int diviver = i*10;
            int k = n % (i * 10);
            if (k > 2 * i -1)
                count += (n / diviver) * i + i;
            else if (k < i)
                count += (n / diviver) * i;
            else
                count += (n / diviver) * i + k - i + 1;
        }
        return count;
    }
};

int main()
{
    Solution s = Solution();
    s.NumberOf1Between1AndN_Solution(1);
    return 0;
}