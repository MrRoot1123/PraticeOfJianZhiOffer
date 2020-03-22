#include <vector>

using namespace std;

/*
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
*/

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        if (array.size() <= 2)
            return result;
        int low = 0, high = array.size() - 1, tmp;
        while (low != high)
        {
            tmp = array[low] + array[high];
            if (tmp < sum)
            {
                ++low;
            }
            else if (tmp == sum)
            {
                result = {array[low], array[high]};
                break;
            }
            else
            {
                --high;
            }
        }
        return result;
    }
};