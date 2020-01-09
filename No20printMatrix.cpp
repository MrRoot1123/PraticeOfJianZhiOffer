/*
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void TravelMatrixInCycle(vector<vector<int> > matrix, vector<int> &res, int &startX, int &startY, int rows,int columns, int &endX, int &endY)
    {
        cout << "endX = " << endX << ", endY = " << endY << endl;
        // 减2是为了把循环的四条边做成完全对称的，可以省去最后的边界情形
        cout << "------" << 111 << "-----" << endl;
        for (int i = startY; i <= endY; ++i)
        {
            cout << matrix[startX][i] << "\t";
            res.push_back(matrix[startX][i]);
        }
        cout << endl;
        if (endY != startY || columns % 2 == 0)
        {
            cout << "------" << 222 << "-----" << endl;
            for (int i = startX; i <= endX; ++i)
            {
                cout << matrix[i][endY+1] << "\t";
                res.push_back(matrix[i][endY+1]);
            }
            cout << endl;
            cout << "2 over" << endl;
            if (endX != startX || rows % 2 == 0)
            {
                cout << "-----" << 333 << "-----" << endl;
                for (int i = endY + 1; i > startY; --i)
                {
                    cout << matrix[endX+1][i] << "\t";
                    res.push_back(matrix[endX+1][i]);
                }
                cout << endl;
                cout << "-----" << 444 << "-----" << endl;
                for (int i = endX+1; i > startX; --i)
                {
                    cout << matrix[i][startY] << "\t";
                    res.push_back(matrix[i][startX]);
                }
                cout << endl;
            }
        }
        return;
    }
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        int rows = matrix.size();
        int columns = matrix[0].size();
        int startX = 0, startY = 0;
        int idx = 0;
        while (startX*2 <= columns && startY*2 <= rows)
        {
            cout << "====================" << endl;
            cout <<"["<< ++idx<< " iteration]: " << startX << " " << startY << endl;
            int endX = rows - startX - 2 >= 0 ? rows - startX -2 : startX;
            int endY = columns - startY - 2 >= 0 ? columns - startY - 2 : startY;
            if (endX < startX || endY < startY) break;
            TravelMatrixInCycle(matrix, res, startX, startY, rows, columns, endX, endY);
            if (startX*2 < columns && endX < rows -1) ++startX;
            if (startY*2 < rows && endY < columns - 1) ++startY;
        }
        return res;
    }
};

int main()
{
    vector<vector<int> > input1({{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}});
    vector<vector<int> > input2({{1,2,3,4,5,6}});
    vector<vector<int> > input3({{1},{2},{3},{4},{5},{6}});
    Solution s = Solution();
    vector<int> res = s.printMatrix(input3);
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
*/


class Solution {
public:
    
    void PrintMatrixInCircle(vector<vector<int> > matrix, int columns, int rows, int start, vector<int> &res)
    {
        int endX = columns - 1 - start;
        int endY = rows - 1 - start;

        // 从左到右打印一行
        for(int i = start; i <= endX; ++i)
        {
            res.push_back(matrix[start][i]);
        }

        // 从上到下打印一列
        if(start < endY)
        {
            for(int i = start + 1; i <= endY; ++i)
            {
                res.push_back(matrix[i][endX]);
            }
        }

        // 从右到左打印一行
        if(start < endX && start < endY)
        {
            for(int i = endX - 1; i >= start; --i)
            {
                res.push_back(matrix[endY][i]);
            }
        }

        // 从下到上打印一行
        if(start < endX && start < endY - 1)
        {
            for(int i = endY - 1; i >= start + 1; --i)
            {
                res.push_back(matrix[i][start]);
            }
        }
    }
    
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> res;
        if(columns <= 0 || rows <= 0)
            return res;
        int start = 0;

        while(columns > start * 2 && rows > start * 2)
        {
            PrintMatrixInCircle(matrix, columns, rows, start, res);
            ++start;
        }
        return res;
    }
};