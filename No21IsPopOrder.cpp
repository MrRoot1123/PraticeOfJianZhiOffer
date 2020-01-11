/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压
栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列
的长度是相等的）
*/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> tmp;
        int idxPush = 0, idxPop = 0;
        bool result = true;
        while (idxPop < popV.size())
        {
            // 压栈
            if (tmp.empty() || tmp.top() != popV[idxPop])
            {
                // 弹出序列中的数字在压栈序列中不存在
                if (idxPush >= pushV.size() && idxPop < popV.size())
                {
                    result = false;
                    break;
                }
                cout << "压栈：" << pushV[idxPush] << endl;
                tmp.push(pushV[idxPush++]);
            }
            else
            {
                cout << "出栈" << tmp.top() << endl;
                // 出栈
                tmp.pop();
                ++idxPop;
            }
        }
        return result;
    }
};