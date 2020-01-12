/*
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/
class Solution {
public:
    void push(int value) {
        m_data.push(value);
        if (m_min.empty() || value < m_min.top())
            m_min.push(value);
        else
            m_min.push(m_min.top());
        return;
    }
    void pop() {
        m_data.pop();
        m_min.pop();
        return;
    }
    int top() {
        return m_data.top();
    }
    int min() {
        return m_min.top();
    }
    private:
    stack<int> m_data;
    stack<int> m_min;
};