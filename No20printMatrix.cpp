class Solution {
public:
    void TravelMatrixInCycle(vector<vector<int> > matrix, vector<int> &res, int &startX, int &startY, int rows,int columns)
    {
        int endX = columns - startX - 2 >= 0 ? columns - startX -2 : startX;
        int endY = rows - startY - 2 >= 0 ? rows - startY - 2 : startY;
        // 减2是为了把循环的四条边做成完全对称的，可以省去最后的边界情形
        for (int i = startX; i <= endX; ++i)
            res.push_back(matrix[startY][i]);
        for (int i = startY; i <= endY; ++i)
            res.push_back(matrix[endX+1][i]);
        if (startX < endX && startY < endY)
        {
            for (int i = endX; i >= 0; --i)
                res.push_back(matrix[endY+1][i]);
            for (int i = endY; i >= 0; --i)
                res.push_back(matrix[startX][i]);
        }
        return;
    }
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        int rows = matrix.size();
        int columns = matrix[0].size();
        int startX = 0, startY = 0;
        while (startX*2 < columns || startY*2 < rows)
        {
            TravelMatrixInCycle(matrix, res, startX, startY, rows, columns);
            if (startX*2 < columns) ++startX;
            if (startY*2 < rows) ++startY;
        }
        return res;
    }
};