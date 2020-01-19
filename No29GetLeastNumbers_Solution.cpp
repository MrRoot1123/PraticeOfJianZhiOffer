#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
                vector<int> result;
        if (input.size() == 0 || k < 0) return result;
        sort(input.begin(),input.end());
        for (int i = 0; i < k && i < input.size(); ++i)
        {
            result[i] = input[i];
        }
        return result;
    }
};

int main()
{
    Solution s = Solution();
    vector<int> test1 = {4,5,1,6,2,7,3,8};
    s.GetLeastNumbers_Solution(test1,4);
    return 0;
}