#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        int low = 1, high = 2, tmpSum;
        while (low < sum)
        {
            tmpSum = (low + high) * (high - low + 1) / 2;
            if (tmpSum < sum)
                ++high;
            else if (tmpSum == sum)
            {
                vector<int> tmp_arr;
                for (int i = low; i <= high; ++i)
                {
                    tmp_arr.push_back(i);
                }
                res.push_back(tmp_arr);
                ++low;
            }
            else
                ++low;
        }
        return res;
    }
};