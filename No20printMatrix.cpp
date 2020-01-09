#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void TravelMatrixInCycle(vector<vector<int> > matrix, vector<int> &res, int &startX, int &startY, int rows,int columns)
    {
        int endX = columns - startX - 2 >= 0 ? columns - startX -2 : startX;
        int endY = rows - startY - 2 >= 0 ? rows - startY - 2 : startY;
        cout << "endX = " << endX << ", endY = " << endY << endl;
        // 减2是为了把循环的四条边做成完全对称的，可以省去最后的边界情形
        cout << "------" << 111 << "-----" << endl;
        for (int i = startY; i <= endY; ++i)
        {
            cout << matrix[startX][i] << "\t";
            res.push_back(matrix[startX][i]);
        }
        cout << endl;
        cout << "------" << 222 << "-----" << endl;
        for (int i = startX; i <= endX; ++i)
        {
            cout << matrix[i][endY+1] << "\t";
            res.push_back(matrix[i][endY+1]);
        }
        cout << endl;
        if (startX <= endX && startY <= endY)
        {
            cout << "-----" << 333 << "-----" << endl;
            for (int i = endY+1; i > startY; --i)
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
        return;
    }
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        int rows = matrix.size();
        int columns = matrix[0].size();
        int startX = 0, startY = 0;
        int idx = 0;
        while (startX*2 < columns || startY*2 < rows)
        {
            cout << "====================" << endl;
            cout <<"["<< ++idx<< " iteration]: " << startX << " " << startY << endl;
            TravelMatrixInCycle(matrix, res, startX, startY, rows, columns);
            if (startX*2 < columns) ++startX;
            if (startY*2 < rows) ++startY;
        }
        return res;
    }
};

int main()
{
    vector<vector<int> > matrix({{1,2,3,4,5,6}});
    Solution s = Solution();
    vector<int> res = s.printMatrix(matrix);
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}