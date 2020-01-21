#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
* 最初的解法，较麻烦

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int maxNum = array[0];
        queue<int> que;
        int tmp;
        for (int i = 0; i < array.size(); ++i)
        {
            // 更新单个最大值，以防所有数均为负
            if (array[i] > maxNum) maxNum = array[i];
            if (i == 0)
            {
                tmp = array[i];
            }
            else
            {
                if (tmp * array[i] >= 0) tmp += array[i];
                else
                {
                    que.push(tmp);
                    tmp = array[i];
                }
                
            }
            
        }
        que.push(tmp);
        queue<int> tmpQue;
        tmpQue = que;
        // 全为负返回最大值
        if (que.size() == 1 && maxNum < 0) return maxNum;
        // 全为正返回所有数字之和
        else if (que.size() == 1 && maxNum > 0) return tmp;
        else
        {
            bool flag = true;
            do
            {
                tmpQue = MergeVec(tmpQue, &flag);
            } while (flag);
        }
        while (!tmpQue.empty())
        {
            if (maxNum < tmpQue.front())
                maxNum = tmpQue.front();
            tmpQue.pop();
        }
        return maxNum;
    }
private:
    queue<int> MergeVec(queue<int> inputQueue, bool* flag)
    {
        int beforeSize = inputQueue.size();
        queue<int> result;
        int tmp = 0;
        while (!inputQueue.empty())
        {
            if (tmp >= 0 && tmp + inputQueue.front() >= 0 && inputQueue.size() >= 2)
            {
                tmp += inputQueue.front();
                inputQueue.pop();
            }
            else
            {
                result.push(tmp);
                tmp = inputQueue.front();
                inputQueue.pop();
            }
            
        }
        result.push(tmp);
        if (result.size() == beforeSize) *flag = false;
        return result;
    }
};
*/

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int maxNum = array[0];
        int tmpSum = 0;
        for (int i = 0; i < array.size(); ++i)
        {
            tmpSum = tmpSum < 0 ? array[i] : tmpSum + array[i];
            maxNum = maxNum < tmpSum ? tmpSum : maxNum;
        }
        return maxNum;
    }
};

int main()
{
    Solution s = Solution();
    vector<int> test1 = {1,-2,3,10,-4,7,2,-5};
    s.FindGreatestSumOfSubArray(test1);
}