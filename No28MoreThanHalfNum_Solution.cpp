#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size() == 1) return numbers[0];
        unordered_map<int, int> numCnt;
        int maxNum, maxCnt = 0;
        for (int i = 0; i < numbers.size(); ++i)
        {
            unordered_map<int, int>::const_iterator got = numCnt.find(numbers[i]);
            if (got == numCnt.end())
                numCnt.insert(pair<int, int>{numbers[i], 1});
            else
            {
                numCnt.at(numbers[i]) = numCnt.at(numbers[i]) + 1;
                if (numCnt.at(numbers[i]) > maxCnt)
                {
                    maxNum = numbers[i];
                    maxCnt = numCnt.at(numbers[i]);
                }
            }
        }
        if (maxCnt > numbers.size()/2)
            return maxNum;
        else
            return 0;
    }
};

int main()
{
    Solution s;
    // vector<int> test = {1,2,3,2,2,2,5,4,2};
    // s.MoreThanHalfNum_Solution(test);
    // vector <int> test2 = {1,2,3,2,4,2,5,2,3};
    // s.MoreThanHalfNum_Solution(test2);
    vector<int> test3 = {1};
    s.MoreThanHalfNum_Solution(test3);
    return 0;
}